/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:01:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 12:02:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	hd_size(t_list **tok_lst)
{
	t_list	*tok;
	size_t	res;

	tok = *tok_lst;
	res = 0;
	while (tok)
	{
		if (tok->toktype == TOK_DL_REDIR)
			res++;
		tok = tok->next;
	}
	return (res);
}
