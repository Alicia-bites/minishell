/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd_dlredir_sep_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:08:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:49:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_cmd_dlredir_sep_token(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->prev->toktype == TOK_PIPE)
	{
		if ((*token_list)->prev->prev->prev->toktype == TOK_CMD
			&& (*token_list)->prev->prev->toktype == TOK_DL_REDIR
			&& (*token_list)->prev->toktype == TOK_HERESEP)
			return (1);
	}
	return (0);
}
