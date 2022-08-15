/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_loop_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:34:24 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 09:27:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*hd_loop_tok(t_list *tok, t_cmd *cmd, long long *hd_exit)
{
	pid_t	pid;

	while (tok && !(tok->toktype == TOK_PIPE))
	{
		if (tok->toktype == TOK_DL_REDIR)
		{
			tok = tok->next;
			if (hd_init(tok, cmd, hd_exit))
				return (NULL);
			pid = fork();
			if (pid < 0)
			{
				*hd_exit = EXIT_FAILURE;
				return (ft_panic_null(-1, __FILE__, ERR_FORK));
			}
			if (pid == 0)
				hd_write(tok, cmd);
			close(cmd->hd_r);
			if (hd_wait(pid, hd_exit))
				return (NULL);
		}
		tok = tok->next;
	}
	return (tok);
}
