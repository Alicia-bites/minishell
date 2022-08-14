/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 15:13:36 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_expanded_heredoc(t_exp_arg exp_arg, t_expanded **expanded_list,
	int i, int *varsize)
{
	static int	index = 0;

	if (!*expanded_list)
		index = 0;
	if (exp_arg.str[i + 1] == '?')
		*varsize = handle_dollar_int(expanded_list, &index);
	else if (ft_isdigit(exp_arg.str[i + 1])
		|| same_with_brackets_number(exp_arg.str, i))
		handle_dollar_number(exp_arg.str, expanded_list, &index, i);
	else if (is_varname(exp_arg.str[i + 1]))
		*varsize = handle_dollar_name(exp_arg, i, expanded_list, &index);
	else if (exp_arg.str[i + 1] == '{')
		*varsize = handle_dollar_brackets(exp_arg, i, expanded_list, &index);
}
