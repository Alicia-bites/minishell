/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:45:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 11:27:28 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_redir(t_list **token_list, int *seen_cmd)
{
	if ((*token_list)->index == 0 || following_pipe(token_list))
	{
		if (is_operator((*token_list)->next->token, seen_cmd) == TOK_R_REDIR
			|| is_operator((*token_list)->next->token, seen_cmd) == TOK_L_REDIR
			|| is_operator((*token_list)->next->token, seen_cmd)
			== TOK_DL_REDIR)
			return (1);
	}
	return (0);
}
