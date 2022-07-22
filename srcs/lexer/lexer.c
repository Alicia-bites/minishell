/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:45:13 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 17:23:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(char *str, int *err)
{
	*err = 0;
	if (lex_quote(str, err) || lex_pipe(str, err) || lex_redir(str, err)
		|| lex_sym(str, err) || lex_brackets(str, err) || lex_space(str, err))
		return ((*err));
	return (0);
}
