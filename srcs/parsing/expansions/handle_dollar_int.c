/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:42:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/10 12:09:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_dollar_int(t_exp_arg exp_arg, int i, t_expanded **expanded_list,
	int *index)
{
	int			j;
	char		*var;
	char		*expanded;
	t_position	position;
	int			varsize;

	i += 2;
	j = i;
	while (exp_arg.str[j] && exp_arg.str[j] != '}')
		j++;
	var = malloc_varname(exp_arg.str, i, j);
	varsize = ft_strlen(var) + 2;
	expanded = handle_dollar_int_expanded();
	position.move_cursor = ft_strlen(expanded) - (ft_strlen(var) + 1);
	position.pos = i - 2;
	if (found_operator(expanded))
		save_operator_position(expanded, position);
	if (exp_arg.str[j] == '\0' || (i >= 3 && exp_arg.str[i - 3] == '<'))
		expanded = "";
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}
