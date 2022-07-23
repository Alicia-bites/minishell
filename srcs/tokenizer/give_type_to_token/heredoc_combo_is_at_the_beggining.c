/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_combo_is_at_the_beggining.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:07:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:44:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	heredoc_combo_is_at_the_beggining(t_list **token_list)
{
	if ((*token_list)->prev->prev->index == 0)
	{
		if ((*token_list)->prev->prev->toktype == TOK_DL_REDIR
			&& ((*token_list)->prev->toktype == TOK_HERESEP))
			return (1);
	}
	return (0);
}
