/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_sym.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:51:05 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 10:51:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lex_sym(char *str, int *err)
{
	if (ft_strstr(str, "\\"))
	{
		*err = BACK_SLASH;
		printf("smbash: syntax error. Please check backslashes.\n");
		return (*err);
	}
	if (ft_strstr(str, ";"))
	{
		*err = SEMICOLON;
		printf("smbash: syntax error. Please check backslashes.\n");
		return (*err);
	}
	return (0);
}
