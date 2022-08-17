/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init_tokfile_find_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:29:04 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 09:29:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * wc < file1 < file2 | < file3 cat | < file5 ls < file6
 */
t_cmd	*fd_init_tokfile_find_cmd(t_ulist **cmd_lst, t_list *tok)
{
	t_list	*tok_fd;
	t_cmd	*cmd;

	(void)cmd_lst;
	tok_fd = tok->next;
	cmd = NULL;
	while (tok->prev && tok->prev->toktype != TOK_PIPE) // BACK TO THE FIRST TOK OF THE COMMAND BLOCK
		tok = tok->prev;
	//printf("first tok of the command block: %s\tptr: %p\n", tok->token, tok);
	while (tok && tok->toktype != TOK_PIPE) // LOOP FROM THE START OF THE COMMAND BLOCK TO THE END OF LINE OR NEXT PIPE
	{
		if (tok->toktype == TOK_CMD || tok->toktype == TOK_BUILTIN)
		{
			//printf("Command for tokfile found: %s\n", tok->token);
			cmd = fd_init_tokfile_loop_cmd(cmd_lst, tok);
			if (cmd)
				return (cmd);
				//printf("Command found in the cmd_lst: ptr = %p\t fullcmd = %s\n", cmd, cmd->fullcmd[0]);
		}
		tok = tok->next;
	}
	return (cmd);
}
