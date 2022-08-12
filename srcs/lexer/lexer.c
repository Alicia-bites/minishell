/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:45:13 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:31:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_spaces_before_pipe(char *str, int *err)
{
	int	not_space;
	int	i;

	i = 0;
	not_space = 0;
	while (str[i] && str[i] != '|')
	{
		if (!ft_isspace(str[i]))
			not_space++;
		i++;
	}
	if (!not_space)
	{
		*err = MISPLACED_PIPE;
		printf("smbash: syntax error. Please check pipes.\n");
		return (*err);
	}
	return (0);
}

int	lexer(char *str, int *err)
{
	*err = 0;
	if (lex_quote(str, err) || lex_pipe(str, err) || lex_redir(str, err)
		|| lex_brackets(str, err) || lex_space(str, err) || lex_sym(str, err)
		||lex_dollar(str, err) || only_spaces_before_pipe(str, err))
		return ((*err));
	return (0);
}
