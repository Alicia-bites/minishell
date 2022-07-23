/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_heredoc_when_heredoc_index_zero.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:11:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/23 13:03:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if we have combo redir+file+cmd+arg
int	combo_heredoc_when_heredoc_index_zero(t_list **token_list)
{
	if ((*token_list)->index >= 3)
	{
		if (heredoc_combo_is_after_pipe(token_list))
			return (1);
	}
	else if ((*token_list)->index >= 2)
		if (heredoc_combo_is_at_the_beggining(token_list))
			return (1);
	return (0);
}
