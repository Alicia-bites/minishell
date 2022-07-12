/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:52:57 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 09:09:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pre_lexer(char *str)
{
	int	err;

	err = 0;
	if (lex_quote(str, &err) || lex_pipe(str, &err) || lex_redir(str, &err)
		|| lex_sym(str, &err) || lex_brackets(str, &err))
			return (err);
		return (err);
	return (0);
}