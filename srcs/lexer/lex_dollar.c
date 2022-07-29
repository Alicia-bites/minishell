/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:45:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/29 15:49:57 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lex_dollar(char *str, int *err)
{
	if (ft_strstr(str, "$$"))
	{
		*err = ERR_DOLLAR;
		printf("smbash: syntax error. Same old story, dollar following dollar.\n");
		return (*err);
	}
	return (0);
}