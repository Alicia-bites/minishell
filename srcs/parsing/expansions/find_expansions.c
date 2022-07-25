/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_expansions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 17:21:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_expansions(t_exp_arg exp_arg, t_expanded **expanded_list, int *full_size)
{
	int	i;
	int	varsize;

	varsize = 0;
	i = 0;
	while (exp_arg.str[i])
	{
		if (exp_arg.str[i] == '$' && exp_arg.str[i + 1] != '\'')
		{
			get_expanded(exp_arg, expanded_list, i, &varsize);
			*full_size -= varsize;
		}
		i++;
	}
}
