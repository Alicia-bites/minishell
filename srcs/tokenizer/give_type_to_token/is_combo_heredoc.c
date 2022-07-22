/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_combo_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:08:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_combo_heredoc(t_list **token_list)
{
	if (following_pipe(token_list))
		return (0);
	if ((*token_list)->index >= 4)
		if (pipe_cmd_dlredir_sep_token(token_list))
			return (1);
	if ((*token_list)->index >= 3)
		if (start_cmd_dlredir_sep_token(token_list))
			return (1);
	if ((*token_list)->index >= 3)
		if (arg_dlredir_sep_token(token_list))
			return (1);
	return (0);
}
