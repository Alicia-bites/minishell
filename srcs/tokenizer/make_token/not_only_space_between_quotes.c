/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_only_space_between_quotes.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 21:23:23 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 22:02:57 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	not_only_space_between_quotes(char *str)
{
	int	not_space;
	int	i;

	not_space = 0;
	i = 1;
	if (!str[i])
		return (-1);
	if ((str[0] == '"' && str[strlen(str) - 1] == '"')
		|| (str[0] == '\'' && str[strlen(str) - 1] == '\''))
	{
		while (i < ft_strlen(str) - 1)
		{
			if (!is_char_space(str[i]))
				not_space++;
			i++;
		}
		printf("not_space = %d\n", not_space);
		return (not_space);
	}
	return (1);
}
