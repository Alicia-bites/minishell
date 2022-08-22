/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_sentinel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:53:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 14:03:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_init_sentinel(t_ulist **cmd_lst, t_list *tok, int sentinel)
{
	t_cmd	*cmd;

	cmd = fd_init_tokfile_find_cmd(cmd_lst, tok);
	if (cmd)
		sentinel = 0;
	return (sentinel);
}
