/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_prompt_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:24:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 19:28:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	give_prompt_back(int signum)
{
	extern t_global	global;

	if (signum == SIGINT)
	{
		global.readline = 1;
		global.exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		return ;
	}
}
