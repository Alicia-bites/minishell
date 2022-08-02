/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_run_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:55:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/02 17:11:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_run_end(t_ulist **cmd_lst, int n_cmd, pid_t pid, int res)
{
	ft_lst_func_lst(cmd_lst, &pipe_close_pfd);
	if (res == 0)
		return (pipe_wait(n_cmd, pid));
	else
	{
		pipe_wait(n_cmd, pid);
		return (1);
	}
}
