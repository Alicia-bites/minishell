/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:22:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 17:39:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_dollars(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	printf("str = %s\n", str);
	while (str[i])
	{
		if (str[i] == '$')
			c++;
		i++;
	}
	return (c);
}
void	check_if_operator(char *str, char *new_str)
{
	int	i;
	extern t_global	global;
	if (is_operator(new_str))
	{			
		global.ignore_op = count_dollars(str);
	}
	printf("global.ignore_op = %d\n", global.ignore_op);
}