/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:22:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 14:17:32 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_malloc_size(char *str)
{
	int	len;
	int	d;
	int	s;
	
	s = 0;
	d = 0;
	len = 0;
	count_quotes_lexer(&s, &d, str);
// 	printf("s = %d\n", s);
	// printf("d = %d\n", d);
	len = s + d;
	return (len);	
}

char *trim_quotes(char *str)
{
	char	*output;
	int		s;
	int		d;
	int		j;
	int		i;
	int		len;
	
	len = 0;
	len = ft_strlen(str) - get_malloc_size(str);
	if (len == ft_strlen(str))
		return (str);
	output = malloc(sizeof(char) * len + 1);
	if (!output)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return (NULL);
	}
	s = 0;
	d = 0;
	j = 0;
	i = 0;
	while (i <= len)
	{
		while (str[j] == '\'' && (!d))
		{
			s++;
			j++;			
		}
		while (str[j] == '\"' && (!s))
		{
			d++;
			j++;			
		}
		if (str[j] == '\'' && !(d % 2))
		{
			j++;
			s++;			
		}
		else if (str[j] == '\"' && !(s % 2))
		{
			j++;
			d++;
		}
		output[i++] = str[j++];
	}
	output[i] = '\0';
	return (output);
}
