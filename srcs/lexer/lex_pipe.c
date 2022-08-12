/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:50:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 16:41:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lex_pipe(char *str, int *err)
{
	int	i;
	int	len;

	if (str[0] == '\0')
		return (0);
	i = 0;
	len = ft_strlen(str);
	if (str[0] == '|' || str[len - 1] == '|')
	{
		*err = MISPLACED_PIPE;
		ft_putendl_fd(MSGERR_PIPE, 2);
		return (*err);
	}
	while (str[i])
	{
		if ((str[i] == '|' && str[i + 1] == '|')
			|| (str[i] == '|' && ft_isspace(str[i + 1]) && str[i + 2] == '|'))
		{
			*err = DOUBLE_PIPE;
			ft_putendl_fd(MSGERR_PIPE, 2);
			return (*err);
		}
		i++;
	}
	return (0);
}
