/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 10:51:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lex_quote(char *str, int *err)
{
	if (count_single(str) % 2 != 0 || count_double(str) % 2 != 0)
	{
		*err = MISSING_QUOTES;
		printf("smbash: syntax *error. Please check quotes.\n");		
	}
	return (*err);
}
