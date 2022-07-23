/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:56:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/23 11:09:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_single(char *str)
{
	int		n_single;
	char	*loc;

	n_single = 0;
	while (*str)
	{
		loc = ft_strstr(str, "'");
		if (!loc)
			return (n_single);
		if (*loc == '\'')
			n_single++;
		str = loc;
		if (*str)
			str++;
	}
	return (n_single);
}	

int	count_double(char *str)
{
	int		n_double;
	char	*loc;

	n_double = 0;
	while (*str)
	{
		loc = ft_strstr(str, "\"");
		if (!loc)
			return (n_double);
		if (*loc == '\"')
			n_double++;
		str = loc;
		if (*str)
			str++;
	}
	return (n_double);
}	

void	count_quotes(char *str, t_chartype *input_list)
{
	input_list->n_single = count_single(str);
	input_list->n_double = count_double(str);
}
