/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_quote_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:26:47 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/21 11:16:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*malloc_tab_quote(int n)
{
	int	*tab;

	tab = malloc(sizeof(int) * (n + 1));
	if (!tab)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	set_minus_one_tab(tab, n + 1);
	return (tab);
}

static int	*fill_tab_index_quote(int pos, int *tab)
{
	static int	i = 0;
	int			n;

	n = find_total_number_op(tab);
	tab[i] = pos;
	i++;
	if (i == n)
		i = 0;
	return (tab);
}

static int	*get_pos_quote(char *expanded, int *tab, int j)
{
	int	pos;

	pos = 0;
	while (expanded[pos])
	{
		if (expanded[pos] == '\'' || expanded[pos] == '\"')
			tab = fill_tab_index_quote(pos + j, tab);
		pos++;
	}
	return (tab);
}

static void	find_and_save_quote_index(char *str, char *new_str,
	t_expanded *expanded_list, int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < ft_strlen(new_str) && i < ft_strlen(str) && new_str[j] == str[i])
	{
		i++;
		j++;
		if (str[i] == '$' && new_str[j] != '$')
		{
			if (expanded_list && (ft_strstr(expanded_list->expanded, "\'") 
				|| ft_strstr(expanded_list->expanded, "\"")))
				*tab = get_pos_quote(expanded_list->expanded, *tab, j);
			if (expanded_list)
			{
				j = j + ft_strlen(expanded_list->expanded);
				expanded_list = expanded_list->next;
			}
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
}

int	*save_quote_index(char *str, char *new_str, t_expanded *expanded_list)
{
	int	n;
	int	*tab;

	tab = 0;
	n = count_quote_in_expanded_list(expanded_list);
	if (n > 0)
	{
		tab = malloc_tab_quote(n);
		tab[n] = '\0';
	}
	if (!tab)
		return (0);
	find_and_save_quote_index(str, new_str, expanded_list, &tab);
	return (tab);
}
