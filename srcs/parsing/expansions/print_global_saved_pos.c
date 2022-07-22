/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_global_saved_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:02:54 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/21 12:03:06 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FOR DEBUG
void	print_global_saved_pos(void)
{
	extern t_global global;
	
	int a = 0;
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	while (global.saved_pos[a])
	{
		printf("global.saved_pos[%d] = %d\n", a, global.saved_pos[a]);
		a++;		
	}
	puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
}