/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_tokfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:33:32 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 15:53:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	hd_tokfile(t_list **tok_lst, t_ulist **cmd_lst,
		t_ulist **env_lst)
{
	t_list		*tok;
	long long	hd_exit;

	tok = *tok_lst;
	hd_exit = 0;
	if (hd_size(tok_lst) == 0)
		return (0);
	sig_hd_unset_action();
	while (tok)
	{
		if (tok->toktype == TOK_DL_REDIR)
			hd_exit = hd_tokfile_link(cmd_lst, tok, env_lst);
		if (hd_exit)
			break ;
		tok = tok->next;
	}
	sig_program_set_action();
	return (hd_exit);
}
