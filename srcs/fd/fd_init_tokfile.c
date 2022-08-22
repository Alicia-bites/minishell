/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:48:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 15:26:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_init_tokfile(t_ulist **cmd_lst, t_list *tok, int mode, int sentinel)
{
	char	*fd_name;
	int		fd;
	t_cmd	*cmd;
	int		res;

	errno = 0;
	fd = 0;
	cmd = NULL;
	res = 0;
	fd_name = tok->next->token;
	cmd = fd_init_tokfile_find_cmd(cmd_lst, tok);
	if (cmd && (cmd->fd_r == -1 || cmd->fd_w == -1))
		return (EXIT_FAILURE);
	else if (!cmd && sentinel > 0)
		return (EXIT_FAILURE);
	fd = fd_open(fd_name, mode);
	if (cmd && fd_init_tokfile_link_cmd_secure(cmd, fd))
		return (EXIT_FAILURE);
	res = fd_init_tokfile_access(fd, fd_name, mode);
	fd_init_tokfile_link_cmd(cmd, fd, mode, NULL);
	return (res);
}
