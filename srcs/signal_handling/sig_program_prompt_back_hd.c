/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_program_prompt_back_hd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:05:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 14:41:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_program_prompt_back_hd(int signum)
{
	extern t_global	g_msl;

	(void)signum;
	g_msl.exit = 130;
	printf("\n");
}
