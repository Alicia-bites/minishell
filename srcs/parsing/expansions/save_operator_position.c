/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_operator_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:02:19 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:41:44 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_operator_in_expansion(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

static int	count_op(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (is_operator_in_expansion(str[i]))
			n++;
		i++;
	}
	return (n);
}

static void	copy_pos(t_position position, int place, int n, char *expanded)
{
	static int		i = 0;
	extern t_global	g_msl;
	static int		save_pos = 0;
	static int		ex_move_cursor = 0;

	if (save_pos > position.pos)
	{
		ex_move_cursor = 0;
		i = 0;
	}
	g_msl.saved_pos[i] = position.pos + place + ex_move_cursor;
	i++;
	save_pos = position.pos;
	if (i == n)
		ex_move_cursor = position.move_cursor;
}

void	save_operator_position(char *expanded, t_position position)
{
	int				i;
	static int		n = 0;
	extern t_global	g_msl;
	static int		save_pos = 0;

	if (save_pos > position.pos)
		n = 0;
	save_pos = position.pos;
	n += count_op(expanded);
	if (!g_msl.saved_pos)
	{
		g_msl.saved_pos = malloc(sizeof(int) * (n + 1));
		ft_bzero(g_msl.saved_pos, n + 1);
	}
	i = 0;
	while (expanded[i])
	{
		if (is_operator_in_expansion(expanded[i]))
			copy_pos(position, i, n, expanded);
		i++;
	}
	g_msl.saved_pos[i++] = '\0';
}
