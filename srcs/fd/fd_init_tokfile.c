/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:48:13 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 09:09:40 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_init_tokfile(t_ulist **cmd_lst, t_list *tok, int mode)
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
	fd = fd_open(fd_name, mode);
	if (cmd && fd_init_tokfile_link_cmd_secure(cmd, fd))
		return (EXIT_FAILURE);
	res = fd_init_tokfile_access(fd, fd_name, mode);
	fd_init_tokfile_link_cmd(cmd, fd, mode, NULL);
	return (res);
}
