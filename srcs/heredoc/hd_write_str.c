/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:57:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 16:06:06 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_write_str(t_list *tok, t_cmd *cmd, char **fullcmd, int mode, t_ulist *envp)
{
	char	*str;

	while (1)
	{
		str = readline(HD_PREFIX);
		if (!str || ft_strcmp(str, tok->token) == 0)
		{
			close(cmd->hd_r);
			if (!str)
				printf("%s: warning: %s\n", SMB_NAME,
					HD_MSG_EOF);
			execve(fullcmd[0], fullcmd, NULL);
		}
		else
		{
			if (mode == HD_EXP)
				str = hd_write_expansion(str, envp);
			ft_putendl_fd(str, cmd->hd_r);
		}
		free(str);
	}
}
