/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_tokfile_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:03:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 16:06:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	hd_tokfile_link(t_ulist **cmd_lst, t_list *tok,
		t_ulist **env_lst)
{
	t_list	*tok_heresep;
	t_cmd	*cmd;
	int		hd;
	pid_t	pid;

	errno = 0;
	tok_heresep = tok->next;
	cmd = NULL;
	hd = -1;
	cmd = fd_init_tokfile_find_cmd(cmd_lst, tok);
	hd = hd_init(tok_heresep, cmd);
	if (hd < 0)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
		return (ft_panic_value(-1, __FILE__, ERR_FORK, EXIT_FAILURE));
	if (pid == 0)
		hd_write(tok_heresep, hd, env_lst);
	close(hd);
	return (hd_wait(pid));
}
