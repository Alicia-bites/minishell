/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   following_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:08 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 17:36:06 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	following_pipe(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_PIPE)
			return (1);
	}
	return (0);
}
