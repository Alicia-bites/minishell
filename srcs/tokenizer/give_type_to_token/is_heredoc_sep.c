/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_heredoc_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:39 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:48:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is a heredoc separator a token that is placed after <<
int	is_heredoc_sep(t_list **token_list)
{
	if ((*token_list)->index >= 1)
		if ((*token_list)->prev->toktype == TOK_DL_REDIR)
			return (1);
	return (0);
}
