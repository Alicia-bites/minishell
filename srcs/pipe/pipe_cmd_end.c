/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:14:22 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/02 17:19:39 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_cmd_end(t_ulist **cmd_lst, t_cmd *cmd, int err_no,
		char **envp)
{
	if (envp)
		ft_free_ptrptr_str(envp);
	pipe_exit(cmd_lst, cmd, err_no);
}
