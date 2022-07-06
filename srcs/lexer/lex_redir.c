/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:51:02 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 10:51:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lex_redir(char *str, int *err)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '>' && str[i + 1] == '<')
		|| (str[i] == '<' && str[i + 1] == '>')
		|| (str[i] == '>' || str[i] == '<')
		&& ft_isspace(str[i + 1])
		&& (str[i + 2] == '>' || str[i + 2] == '<')
		|| ((str[i] == '>' && str[i + 1] ==  '>' && str[i + 2] == '>')
		|| str[i] == '<' && str[i + 1] == '<' && str[i + 2] == '<')
		)
		{
			*err = MISPLACED_REDIR;
			printf("smbash: syntax error. Please check redirections.\n");
			return (*err);
		}
		i++;
	}
	return (0);
}
