/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:42:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/10 12:22:09 by amarchan         ###   ########.fr       */
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

	expanded = handle_dollar_int_expanded();
	position.move_cursor = ft_strlen(expanded) - (2 + 1);
	position.pos = i;
	*expanded_list = create_dollar_list(expanded, (*index)++);
	varsize = 2;
	return (varsize);
}
