/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_link_in_out_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:04:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 13:44:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_link_in_out_file(t_list **tok_lst, t_ulist **cmd_lst, int mode)
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
		tok = fd_loop_tok(tok, cmd, mode);
		cmd = NULL;
		if (tok)
			tok = tok->next;
		obj = obj->next;
	}
}
