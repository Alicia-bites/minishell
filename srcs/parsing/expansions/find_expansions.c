/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_expansions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 14:06:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	found_bad_combo(int i, char *str)
{
	if (i + 1 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '$')
		return (1);
	else if (i + 1 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '\'')
		return (1);
	else if (i + 3 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '{'
		&& str[i + 2] == '$' && str[i + 3] == '}')
		return (1);
	else if (i + 1 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '"')
		return (1);
	else if (i + 1 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '>')
		return (1);
	return (0);
}

static int	is_heredoc_delimiter(char *str, int pos)
{
	if (pos > 1)
		pos--;
	while (str[pos] && (str[pos] == '\"' || str[pos] == '\''))
		pos--;
	if (pos > 2 && ft_isspace(str[pos]))
	{
		while (str[pos] && ft_isspace(str[pos]))
			pos--;
		if (pos > 1 && str[pos] == '<' && str[pos - 1] == '<')
			return (1);
	}
	return (0);
}

// varsize is the size of the variable before it gets expanded
// you wanna deduct from the full size.
void	find_expansions(t_exp_arg exp_arg, t_expanded **expanded_list,
	int *full_size)
{
	int	i;
	int	varsize;

	varsize = 0;
	i = 0;
	while (exp_arg.str[i])
	{
		if (exp_arg.str[i] == '$' && !found_bad_combo(i, exp_arg.str)
			&& !between_single_quotes(exp_arg.str, i)
			&& !is_heredoc_delimiter(exp_arg.str, i)
			&& !nothing_follows_follar(exp_arg.str, i))
		{
			get_expanded(exp_arg, expanded_list, i, &varsize);
			*full_size -= varsize;
		}
		i++;
	}
}
