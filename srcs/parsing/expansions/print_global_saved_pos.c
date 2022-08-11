/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_global_saved_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:02:54 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:42:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FOR DEBUG
void	print_global_saved_pos(void)
{
	int				a;
	extern t_global	g_msl;

	a = 0;
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	while (g_msl.saved_pos[a])
	{
		printf("g_msl.saved_pos[%d] = %d\n", a, g_msl.saved_pos[a]);
		a++;
	}
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}
