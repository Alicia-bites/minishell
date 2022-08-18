/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check_tok_lst_redir.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:27:16 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check if active token is a redirection token and if its next one is a
 * file token
 *
 * @PARAM:
 * t_list *tok_lst: token node
 *
 * @RETURN:
 * 0: ok
 * > 0: error
 */
int	cmd_check_tok_lst_redir(t_list *tok)
{
	t_list	*next;

	next = NULL;
	if (tok->next)
		next = tok->next;
	if (tok->toktype == TOK_L_REDIR || tok->toktype == TOK_R_REDIR
		|| tok->toktype == TOK_DR_REDIR)
	{
		if (!next || next->toktype != TOK_FILE)
			return (ft_panic(-1, __func__, ERR_TOK_REDIR));
	}
	return (0);
}
