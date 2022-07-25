/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:03:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 11:15:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lex_space(char *str, int *err)
{
	if (ft_isspace(str[0]) && str[1] == '|'
		|| ((ft_strlen(str) > 2)
			&& (str[ft_strlen(str) - 2]) == '|')
		&& ft_isspace(str[ft_strlen(str) - 1]))
	{
		*err = MISPLACED_PIPE;
		printf("smbash: syntax error. Please check pipes.\n");
		return (*err);
	}
	return (0);
}
