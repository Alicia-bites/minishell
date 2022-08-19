/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_ok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:22:52 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 19:32:36 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_exp_quote(int pos, int *tab)
{
	int	j;

	j = 0;
	if (!tab)
		return (0);
	if (tab[j])
	{
		while (tab[j])
		{
			if (pos == tab[j])
				return (1);
			j++;
		}
	}
	return (0);
}

int	copy_ok(char *str, int j, int *tab)
{
	if ((str[j] != '\'' && str[j] != '\"')
		|| (str[j] == '\''
			&& (between_double_quotes(str, j) || is_exp_quote(j, tab)))
		|| (str[j] == '\"'
			&& (between_single_quotes(str, j) || is_exp_quote(j, tab))))
		return (1);
	return (0);
}
