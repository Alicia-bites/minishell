/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_program_prompt_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:47:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 15:18:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @BRIEF:
 * do a carriage return and replace the line to prompt back
 *
 * @PARAM:
 * int signum: received signal number
 *
 * @RETURN:
 * N/A
 */
void	sig_program_prompt_back(int signum)
{
	extern t_global	g_msl;

	g_msl.exit = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
