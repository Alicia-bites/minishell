/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:57:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 09:01:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_write(t_list *tok, t_cmd *cmd)
{
	char	*str;
	char	*filename;
	char	*fullcmd[2];

	sig_hd_set_action();
	filename = HD_BIN_TRUE;
	fullcmd[0] = HD_BIN_TRUE;
	fullcmd[1] = NULL;
	while (1)
	{
		str = readline("heredoc: ");
		if (!str || ft_strcmp(str, tok->token) == 0)
		{
			close(cmd->hd_r);
			if (!str)
				printf("bash: warning: %s\n", HD_MSG_EOF);
			execve(filename, fullcmd, NULL);
		}
		else
			ft_putendl_fd(str, cmd->hd_r);
		free(str);
	}
	return (0);
}
