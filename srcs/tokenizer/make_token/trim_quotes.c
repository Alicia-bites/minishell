/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:22:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/26 17:52:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*built_output_d_quote(char *str, int count_quotes)
{
	int		i;
	int		j;
	char	*output;

	output = malloc(sizeof(char) * (ft_strlen(str) - count_quotes + 1));
	if (!output)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i <= (ft_strlen(str) - count_quotes))
	{
		if (str[j] != '\"')
			output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
	return (output);
}

static char	*trim_double_quotes(char *str)
{
	int		i;
	char	*output;
	int		count_quotes;
	
	i= 0;
	count_quotes = 0;
	output = NULL;
	while (str[i])
	{
		if (str[i] == '\"')
			count_quotes++;
		i++;
	}
	output = built_output_d_quote(str, count_quotes);
	return (output);
}

static char	*built_output_s_quote(char *str, int count_quotes)
{
	int		i;
	int		j;
	char	*output;

	output = malloc(sizeof(char) * (ft_strlen(str) - count_quotes + 1));
	if (!output)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (i <= (ft_strlen(str) - count_quotes))
	{
		if (str[j] != '\'')
			output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
	return (output);
}

static char	*trim_single_quotes(char *str)
{
	int		i;
	char	*output;
	int		count_quotes;
	
	i= 0;
	output = NULL;
	count_quotes = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count_quotes++;
		i++;
	}
	output = built_output_s_quote(str, count_quotes);
	printf("output = %s\n", output);
	return (output);
}

char *trim_quotes(char *str)
{
	char	*output;
	
	if (str[0] == '\"')
		output = trim_double_quotes(str);
	else if (str[0] == '\'')
		output = trim_single_quotes(str);
	else if (str[0] != '\'' && str[0] != '\"')
		return (str);
	return (output);
}