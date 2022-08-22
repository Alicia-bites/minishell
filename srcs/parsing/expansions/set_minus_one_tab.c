/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_minus_one_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:35:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/20 19:03:39 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_minus_one_tab(int *tab, size_t n)
{
	size_t	i;

	i = 0;
	if (!tab || n == 0)
		return ;
	while (i < n)
	{
		tab[i] = -1;
		i++;
	}
}
