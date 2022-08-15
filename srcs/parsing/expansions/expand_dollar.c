/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 11:43:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_dollar(t_exp_arg exp_arg, int **tab)
{
	int					malloc;
	char				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	expanded_list = NULL;
	malloc = 0;
	find_expansions(exp_arg, &expanded_list, &full_size);
	if (ft_strstr(exp_arg.str, "$\'") || ft_strstr(exp_arg.str, "$\""))
	{
		exp_arg.str = remove_dollars(exp_arg.str);
		if (!exp_arg.str)
			return (NULL);
		malloc++;
	}
	if (!expanded_list)
		return (exp_arg.str);
	full_size += get_full_size(expanded_list) + ft_strlen(exp_arg.str);
	new_str = insert_expansions(full_size, expanded_list, exp_arg.str);
	*tab = save_operator_index(exp_arg.str, new_str, expanded_list);
	ft_lstclear_dollar(&expanded_list);
	if (malloc)
		free(exp_arg.str);
	return (new_str);
}
