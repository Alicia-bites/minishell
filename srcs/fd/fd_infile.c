/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_infile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:04:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 10:29:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_infile(t_list **tok_lst, t_ulist **cmd_lst)
{
	t_list	*tok;
	t_ulist	*obj;
	t_cmd	*cmd;

	tok = *tok_lst;
	obj = *cmd_lst;
	cmd = NULL;
	while (obj && tok)
	{
		cmd = (t_cmd *)obj->content;
		tok = fd_infile_loop_tok(tok, cmd);
		cmd = NULL;
		if (tok)
			tok = tok->next;
		obj = obj->next;
	}
}
