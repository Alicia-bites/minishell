/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:57:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 15:53:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_write_str(t_list *tok, char **fullcmd, int hd, t_ulist **env_lst)
{
	char	*str;
	int		mode;

	mode = hd_write_mode(tok);
	if (mode == HD_NO_EXP)
		tok->token = trim_quotes(tok->token);
	while (1)
	{
		str = readline(HD_PREFIX);
		if (!str || ft_strcmp(str, tok->token) == 0)
		{
			close(hd);
			if (!str)
				printf("%s: warning: %s\n", SMB_NAME,
					HD_MSG_EOF);
			execve(fullcmd[0], fullcmd, NULL);
		}
		else
		{
			if (mode == HD_EXP)
				str = hd_write_expansion(str, env_lst);
			ft_putendl_fd(str, hd);
		}
		free(str);
	}
}
