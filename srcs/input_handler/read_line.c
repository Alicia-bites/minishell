/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 17:22:25 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global	global;

void	read_line(char **str)
{
	global.readline = 1;
	while (global.readline)
	{
		global.readline = 0;
		*str = readline("$: ");
		return ;
	}
}
