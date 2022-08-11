/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 16:08:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



char	*expand_dollar(t_exp_arg exp_arg, int **tab)
{
	char				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	expanded_list = NULL;
	find_expansions(exp_arg, &expanded_list, &full_size);
	exp_arg.str = remove_dollars(exp_arg.str);
	if (!expanded_list)
	{
		return (exp_arg.str);
	}
	full_size += get_full_size(expanded_list) + ft_strlen(exp_arg.str);
	new_str = insert_expansions(full_size, expanded_list, exp_arg.str);
	*tab = save_operator_index(exp_arg.str, new_str, expanded_list);
	ft_lstclear_dollar(&expanded_list);
	ft_lstclear_back_dollar(&expanded_list);
	return (new_str);
}
