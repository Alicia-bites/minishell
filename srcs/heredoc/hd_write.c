/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:57:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 16:06:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_write(t_list *tok, t_cmd *cmd, t_ulist *envp)
{
	char	*fullcmd[2];
	int		mode;

	sig_hd_set_action();
	fullcmd[0] = HD_BIN_TRUE;
	fullcmd[1] = NULL;
	mode = hd_write_mode(tok);
	hd_write_str(tok, cmd, fullcmd, mode, envp);
}
