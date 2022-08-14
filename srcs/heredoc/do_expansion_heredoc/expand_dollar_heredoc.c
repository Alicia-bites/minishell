/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:29:08 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 15:25:39 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_dollar_heredoc(t_exp_arg exp_arg, int **tab)
{
	char				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	expanded_list = NULL;
	find_expansions_heredoc(exp_arg, &expanded_list, &full_size);
	if (!expanded_list)
		return (exp_arg.str);
	full_size += get_full_size(expanded_list) + ft_strlen(exp_arg.str);
	new_str = insert_expansions_heredoc(full_size, expanded_list, exp_arg.str);
	*tab = save_operator_index(exp_arg.str, new_str, expanded_list);
	ft_lstclear_dollar(&expanded_list);
	return (new_str);
}
