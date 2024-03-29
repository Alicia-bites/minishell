/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_operator_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:07:53 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/20 19:33:11 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*malloc_tab(int n)
{
	int	*tab;

	tab = malloc(sizeof(int) * (n + 1));
	if (!tab)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	set_minus_one_tab(tab, n);
	return (tab);
}

static int	*fill_tab_index(int pos, int *tab)
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

static int	*get_pos(char *expanded, int *tab, int j)
{
	int	pos;

	pos = 0;
	while (expanded[pos])
	{
		if (is_operator_in_expansion(expanded[pos]))
			tab = fill_tab_index(pos + j, tab);
		pos++;
	}
	return (tab);
}

static void	find_and_save_op_index(char *str, char *new_str,
	t_expanded *expanded_list, int **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < ft_strlen(new_str) && i < ft_strlen(str) && new_str[j] == str[i])
	{
		i++;
		j++;
		if (str[i] == '$' && new_str[j] != '$')
		{
			if (expanded_list && found_operator(expanded_list->expanded))
				*tab = get_pos(expanded_list->expanded, *tab, j);
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

int	*save_operator_index(char *str, char *new_str, t_expanded *expanded_list)
{
	int	n;
	int	*tab;

	tab = 0;
	n = count_op_in_expanded_list(expanded_list);
	if (n > 0)
	{
		tab = malloc_tab(n);
		tab[n] = '\0';
	}
	if (!tab)
		return (0);
	find_and_save_op_index(str, new_str, expanded_list, &tab);
	return (tab);
}
