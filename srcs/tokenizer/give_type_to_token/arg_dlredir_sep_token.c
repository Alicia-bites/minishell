/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_dlredir_sep_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:04:54 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:05:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_dlredir_sep_token(t_list **token_list)
{
	if ((*token_list)->prev->prev->prev->toktype == TOK_ARG
		&& (*token_list)->prev->prev->toktype == TOK_DL_REDIR
		&& (*token_list)->prev->toktype == TOK_HERESEP)
		return (1);
	return (0);
}
