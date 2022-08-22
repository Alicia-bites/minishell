/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 07:41:35 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 14:51:57 by abarrier         ###   ########.fr       */
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
	int		sentinel;

	tok = *tok_lst;
	res = 0;
	sentinel = 0;
	while (tok)
	{
		sentinel = fd_init_sentinel(cmd_lst, tok, sentinel);
		if (tok->toktype == TOK_L_REDIR)
			res += fd_init_tokfile(cmd_lst, tok, O_RDONLY, sentinel);
		else if (tok->toktype == TOK_R_REDIR)
			res += fd_init_tokfile(cmd_lst, tok, O_WRONLY, sentinel);
		else if (tok->toktype == TOK_DR_REDIR)
			res += fd_init_tokfile(cmd_lst, tok, O_APPEND, sentinel);
		else if (tok->toktype == TOK_DL_REDIR)
			res += fd_init_tokfile_hd(cmd_lst, tok);
		if (!fd_init_tokfile_find_cmd(cmd_lst, tok) && sentinel == 0)
			sentinel = res;
		tok = tok->next;
	}
	return (sentinel);
}
