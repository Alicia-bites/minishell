/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check_tok_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:20:18 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 16:51:23 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check each token and its next token structure
 *
 * @PARAM:
 * t_list **tok_lst: token list
 *
 * @RETURN:
 * 0: ok
 * > 0: error
 */
int	cmd_check_tok_lst(t_list **tok_lst)
{
	t_list	*tok;

	tok = *tok_lst;
	if (!tok)
		return (ft_panic(-1, __FILE__, ERR_NOTOK));
	while (tok)
	{
		if (cmd_check_tok_lst_redir(tok))
			return (1);
		if (cmd_check_tok_lst_hd(tok))
			return (1);
		tok = tok->next;
	}
	return (0);
}
