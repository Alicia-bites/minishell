/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:53:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/22 13:30:23 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_exit(t_ulist **cmd_lst, t_cmd *cmd)
{
	rl_clear_history();
	ft_lstclear(cmd->tok_lst);
	ft_lst_free(cmd->env_lst, &env_free);
	ft_lst_free(cmd_lst, &cmd_free);
	exit(1);
}
