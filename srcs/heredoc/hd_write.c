/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:57:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 17:13:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_write(t_list *tok, int hd, t_ulist **env_lst)
{
	char	*fullcmd[2];

	sig_hd_set_action();
	fullcmd[0] = HD_BIN_TRUE;
	fullcmd[1] = NULL;
	hd_write_str(tok, fullcmd, hd, env_lst);
}
