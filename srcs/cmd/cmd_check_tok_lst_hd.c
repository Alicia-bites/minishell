/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check_tok_lst_hd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 08:25:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 08:32:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check if active token is a redirection token and if its next one is a
 * heredoc separator token
 *
 * @PARAM:
 * t_list *tok_lst: token node
 *
 * @RETURN:
 * 0: ok
 * >= 0: error
 */
int	cmd_check_tok_lst_hd(t_list *tok)
{
	t_list	*next;

	next = NULL;
	if (tok->next)
		next = tok->next;
	if (tok->toktype == TOK_DL_REDIR)
	{
		if (!next || next->toktype != TOK_HERESEP)
			return (ft_panic(-1, __FILE__, ERR_TOK_HERESEP));
	}
	return (0);
}
