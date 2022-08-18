/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_program_prompt_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:47:26 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 14:52:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
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
	extern long long	g_exit;

	(void)signum;
	g_exit = 130;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
