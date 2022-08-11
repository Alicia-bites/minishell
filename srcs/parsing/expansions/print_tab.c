/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:08:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 16:08:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;		
	}
	puts("-----------------------------------------------");
}
