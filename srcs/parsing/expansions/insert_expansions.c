/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_expansions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:49:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 16:09:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*malloc_newstr(int full_size, t_expanded **expanded_list)
{
	char	*new_str;

	new_str = malloc(sizeof(char) * (full_size + 1));
	if (!new_str)
	{
		ft_lstclear_dollar(expanded_list);
		return (ft_panic_null(MALLOC_FAILURE, __FILE__, NULL));
	}
	ft_bzero(new_str, sizeof(char) * (full_size + 1));
	return (new_str);
}

static void	travel_to_next_str(int *k, char *str)
{
	while (ft_isalnum(str[*k]) || str[*k] == '{' || str[*k] == '}')
	{
		if (str[*k] == '}' && !bracket_is_after_dollar(str, *k))
			break ;
		if (str[*k - 1] == '}' && ft_isalnum(str[*k]))
			break ;
		(*k)++;
	}
}

static void	copy_expanded(char *str, t_expanded **expanded_list,
	t_cursor *cursor, char *new_str)
{
	int	j;

	if (cursor->k < ft_strlen(str) -1)
	{
		if (str[cursor->k] == '$' && str[cursor->k + 1] != '"'
			&& str[cursor->k + 1] != '\''
			&& !between_single_quotes(str, cursor->k))
		{
			j = 0;
			if (*expanded_list && (*expanded_list)->expanded)
			{
				while ((*expanded_list)->expanded[j])
					new_str[cursor->i++] = (*expanded_list)->expanded[j++];
			}
			if (*expanded_list)
				(*expanded_list) = (*expanded_list)->next;
			cursor->k++;
			travel_to_next_str(&cursor->k, str);
		}
	}
}

static int	interrogation_point_follows_dollar(char *str, int i)
{
	if (str[i] == '?' && !between_quotes(str, i))
	{
		if (i >= 1 && str[i - 1] == '$')
			return (1);
		else
			return (0);
	}
	return (0);
}

char	*insert_expansions(int full_size, t_expanded *expanded_list, char *str)
{
	t_cursor	cursor;
	int			j;
	char		*new_str;

	new_str = malloc_newstr(full_size, &expanded_list);
	cursor.i = 0;
	cursor.k = 0;
	full_size -= count_double(str);
	while (cursor.i < full_size && cursor.k < ft_strlen(str))
	{
		copy_expanded(str, &expanded_list, &cursor, new_str);
		if (str[cursor.k] && cursor.i <= full_size
			&& str[cursor.k] != '$'
			&& !interrogation_point_follows_dollar(str, cursor.k)
			|| (str[cursor.k] == '$' && between_single_quotes(str, cursor.k)))
			new_str[cursor.i++] = str[cursor.k++];
		else if (str[cursor.k] == '$' && !between_single_quotes(str, cursor.k))
			cursor.k++;
	}
	new_str[cursor.i] = '\0';
	return (new_str);
}
