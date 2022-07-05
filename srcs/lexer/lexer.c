/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:52:57 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/05 19:31:35 by amarchan         ###   ########.fr       */
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

int	lex_pipe(char *str, int *err)
{
	int len;
	
	len = ft_strlen(str);
	if (str[0] == '|' || str[len - 1] == '|')
	{
		*err = MISPLACED_PIPE;
		printf("smbash: syntax error. Please check pipes.\n");
	}
	return (*err);
}

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

int	lexer(char *str)
{
	int	err;

	err = 0;
	if (lex_quote(str, &err) || lex_pipe(str, &err) || lex_redir(str, &err))
		return (err);
	return (0);
}