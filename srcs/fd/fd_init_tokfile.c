/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:48:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/20 16:30:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_init_tokfile(t_ulist **cmd_lst, t_list *tok, int mode)
{
	char	*fd_name;
	int		fd;
	// int		res_open;
	t_cmd	*cmd;

	errno = 0;
	fd = 0;
	cmd = NULL;
	fd_name = tok->next->token;
	cmd = fd_init_tokfile_find_cmd(cmd_lst, tok);
	fd = fd_open(fd_name, mode);
	if (cmd && fd_init_tokfile_link_cmd_secure(cmd, fd))
		return ;
	fd_init_tokfile_access(fd, fd_name, mode);
	fd_init_tokfile_link_cmd(cmd, fd, mode, NULL);
}
