/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:33:32 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 15:49:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_link(t_list **tok_lst, t_ulist **cmd_lst)
{
	t_list		*tok;
	t_ulist		*obj;
	t_cmd		*cmd;
	long long	hd_exit;

	tok = *tok_lst;
	obj = *cmd_lst;
	cmd = NULL;
	hd_exit = 0;
	if (hd_size(tok_lst) == 0)
		return (0);
	sig_hd_unset_action();
	while (obj && tok)
	{
		cmd = (t_cmd *)obj->content;
		tok = hd_loop_tok(tok, cmd, &hd_exit);
		cmd = NULL;
		if (tok)
			tok = tok->next;
		if (hd_exit)
			return (1);
		obj = obj->next;
	}
	sig_program_set_action();
	return (0);
}
