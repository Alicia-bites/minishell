/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dollars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:48:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/09 14:48:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_my_dollars(char *str)
{
	int	i;
	int n;
	
	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (i + 1 < ft_strlen(str) && str[i] == '$'
			&& (str[i + 1] == '\'' || str[i + 1] == '"'))
			n++;
		i++;
	}
	return (n);
}

char	*remove_dollars( char *str)
{
	int	i;
	int j;
	int	n;
	char *output;

	n = ft_strlen(str) - count_my_dollars(str);
	output = malloc(sizeof(char) * (n + 1));
	if (!output)
		return (ft_panic_null(MALLOC_FAILURE, __FILE__, NULL));
	i = 0;
	j = 0;
	while (i < n)
	{
		if (j + 1 < ft_strlen(str) && str[j] == '$'
			&& (str[j + 1] == '\'' || str[j + 1] == '"'))
				j++;
		output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
	return (output);
}