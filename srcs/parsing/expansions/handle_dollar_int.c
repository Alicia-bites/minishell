/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:42:30 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/13 15:06:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_dollar_int(t_exp_arg exp_arg, int i, t_expanded **expanded_list,
	int *index)
{
	int			j;
	char		*var;
	char		*expanded;
	int			varsize;

	expanded = handle_dollar_int_expanded();
	*expanded_list = create_dollar_list(expanded, (*index)++);
	varsize = 2;
	return (varsize);
}
