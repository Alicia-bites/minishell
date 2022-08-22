/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_find_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:29:04 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/20 16:31:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * wc < file1 < file2 | < file3 cat | < file5 ls < file6
 */
t_cmd	*fd_init_tokfile_find_cmd(t_ulist **cmd_lst, t_list *tok)
{
	// t_list	*tok_fd;
	t_cmd	*cmd;

	(void)cmd_lst;
	// tok_fd = tok->next;
	cmd = NULL;
	while (tok->prev && tok->prev->toktype != TOK_PIPE)
		tok = tok->prev;
	while (tok && tok->toktype != TOK_PIPE)
	{
		if (tok->toktype == TOK_CMD || tok->toktype == TOK_BUILTIN)
		{
			cmd = fd_init_tokfile_loop_cmd(cmd_lst, tok);
			if (cmd)
				return (cmd);
		}
		tok = tok->next;
	}
	return (cmd);
}
