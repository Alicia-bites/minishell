/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:59:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 16:34:46 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_operator(t_list *token_list, int *seen_cmd)
{
	if (token_list->toktype == TOK_NOT_OP)
		return (1);
	if (is_operator(token_list->token, seen_cmd))
		return (0);
	return (1);
}
