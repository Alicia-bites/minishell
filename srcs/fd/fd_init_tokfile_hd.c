/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_hd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:27:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 09:05:45 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_init_tokfile_hd(t_ulist **cmd_lst, t_list *tok)
{
	char	*hd_name;
	int		hd;
	t_cmd	*cmd;

	errno = 0;
	hd = 0;
	cmd = NULL;
	hd_name = hd_create_name(tok->next);
	cmd = fd_init_tokfile_find_cmd(cmd_lst, tok->next);
	if (!hd_name)
	{
		if (cmd)
			fd_init_tokfile_link_cmd_secure(cmd, hd);
		return (EXIT_FAILURE);
	}
	hd = fd_open(hd_name, O_RDONLY);
	if (cmd && fd_init_tokfile_link_cmd_secure(cmd, hd))
	{
		free(hd_name);
		return (EXIT_FAILURE);
	}
	fd_init_tokfile_access(hd, hd_name, O_RDONLY);
	fd_init_tokfile_link_cmd(cmd, hd, O_RDONLY, hd_name);
	return (0);
}
