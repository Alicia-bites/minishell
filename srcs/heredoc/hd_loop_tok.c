/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_loop_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:34:24 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/08 18:18:56 by abarrier         ###   ########.fr       */
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
			if (!hd_create_name(tok, cmd))
				return (NULL);
			if (hd_open(cmd))
				return (NULL);
//			sig_hd_unset_action();
			pid = fork();
			if (pid < 0)
				return (ft_panic_null(-1, __FILE__, ERR_FORK));
			if (pid == 0)
			{
				sig_hd_set_action();
				hd_write(tok, cmd);
			}
			close(cmd->hd_r);
			if (hd_wait(pid) == 1)
			{
				*hd_exit = 1;
//				sig_program_set_action();
				return (NULL);
			}
//			sig_program_set_action();
		}
		tok = tok->next;
	}
	return (tok);
}
