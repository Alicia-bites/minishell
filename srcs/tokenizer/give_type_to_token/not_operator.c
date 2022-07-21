/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_operator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:59:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/21 18:59:58 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_operator(t_list *token_list)
{
	if (token_list->toktype == TOK_NOT_OP)
		return (1);
	if (is_operator(token_list->token))
		return (0);
	return (1);
}
