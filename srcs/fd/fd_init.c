/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:41:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 10:32:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_init(t_list ** tok_lst, t_ulist **cmd_lst)
{
	t_list	*tok;

	tok = *tok_lst;
	while (tok)
	{
		if (tok->toktype == TOK_L_REDIR)
			fd_init_tokfile(cmd_lst, tok, O_RDONLY);
		else if (tok->toktype == TOK_R_REDIR)
			fd_init_tokfile(cmd_lst, tok, O_WRONLY);
		else if (tok->toktype == TOK_DR_REDIR)
			fd_init_tokfile(cmd_lst, tok, O_APPEND);
		tok = tok->next;
	}
}
