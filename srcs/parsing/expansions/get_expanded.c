/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 17:25:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_expanded(t_exp_arg exp_arg, t_expanded **expanded_list,
	int i, int *varsize)
{
	static int	index = 0;
	
	if (i > 1 && exp_arg.str[i - 1] == '\'' && !between_quotes(exp_arg.str, i - 1))
		return ;
	if (!*expanded_list)
		index = 0;
	if (exp_arg.str[i + 1] == '?')
		*varsize = handle_dollar_int(exp_arg, i, expanded_list, &index);
	if (ft_isdigit(exp_arg.str[i + 1]) || same_with_brackets_number(exp_arg.str, i))
		handle_dollar_number(exp_arg.str, expanded_list, &index, i);
	else if (is_varname(exp_arg.str[i + 1]))
		*varsize = handle_dollar_name(exp_arg, i, expanded_list, &index);
	else if (exp_arg.str[i + 1] == '{')
		*varsize = handle_dollar_brackets(exp_arg, i, expanded_list, &index);
}
