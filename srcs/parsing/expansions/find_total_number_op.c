/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_total_number_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:18:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 16:18:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_total_number_op(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
