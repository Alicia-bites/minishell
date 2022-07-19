/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_redir_when_redir_index_zero.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 18:19:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Check if we have combo redir+file+cmd+arg
int	is_combo_redir_when_redir_index_zero(t_list **token_list)
{
	if ((*token_list)->index >= 3)
	{
		if (combo_is_after_pipe(token_list))
			return (1);	
	}
	else if ((*token_list)->index >= 3)
		if (combo_is_at_the_beggining(token_list))
			return (1);
	return (0);
}
