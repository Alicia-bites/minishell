/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_combo_is_after_pipe.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:07:37 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:44:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_combo_is_after_pipe(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->toktype == TOK_PIPE)
	{
		if ((*token_list)->prev->prev->toktype == TOK_DL_REDIR
			&& ((*token_list)->prev->toktype == TOK_HERESEP))
			return (1);
	}
	return (0);
}
