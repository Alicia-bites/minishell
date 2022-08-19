/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:41:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/19 18:28:47 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * loop through the token list to open in a specific mode the file
 * O_RDONLY: for "< file1"
 * O_WRONLY: for "> file1"
 * O_APPEND: for ">> file1"
 *
 * there is no mode for heredoc because it is always O_RDONLY
 *
 * @PARAM:
 * t_list **tok_lst: token list
 * t_ulist **cmd_lst: command list
 *
 * @RETURN:
 * 0: ok
 * > : error
 */
int	fd_init(t_list **tok_lst, t_ulist **cmd_lst)
{
	t_list	*tok;
	int		res;

	tok = *tok_lst;
	res = 0;
	while (tok)
	{
		if (tok->toktype == TOK_L_REDIR)
			res += fd_init_tokfile(cmd_lst, tok, O_RDONLY);
		else if (tok->toktype == TOK_R_REDIR)
			res += fd_init_tokfile(cmd_lst, tok, O_WRONLY);
		else if (tok->toktype == TOK_DR_REDIR)
			res += fd_init_tokfile(cmd_lst, tok, O_APPEND);
		else if (tok->toktype == TOK_DL_REDIR)
			res += fd_init_tokfile_hd(cmd_lst, tok);
		tok = tok->next;
	}
	return (res);
}
