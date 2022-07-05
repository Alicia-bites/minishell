/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:52:57 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/05 14:31:16 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(char *str)
{
	int	err;

	err = 0;
	if (count_single(str) % 2 != 0 || count_double(str) % 2 != 0)
	{
		err = MISSING_QUOTES;
		printf("Error in command line. Please check quotes.\n");		
	}
	return (err);
}