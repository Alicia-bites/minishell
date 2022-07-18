/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:52:57 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 14:02:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lex_space(char *str, int *err)
{
	if (ft_isspace(str[0]) && str[1] == '|'
		|| (str[ft_strlen(str) - 2]) == '|' && ft_isspace(str[ft_strlen(str) - 1]))
		{
			*err = MISPLACED_PIPE;
			printf("smbash: syntax error. Please check pipes.\n");
			return (*err);
		}
	return (0);
}

int	pre_lexer(char *str, int *err)
{
	*err = 0;
	if (lex_quote(str, err) || lex_pipe(str, err) || lex_redir(str, err)
		|| lex_sym(str, err) || lex_brackets(str, err) || lex_space(str, err))
		return ((*err));
	return (0);
}