/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:02:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 10:59:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//The only case len could be equal to 1 is when str only contains one quote.
//Since we are going to deduct get_malloc_size from ft_strlen(str) we would end
//up with len = 1 - 1 = 0. Yet, we want len to be 1 because if this quote is 
//lonly, it necessarily means it is out of an expansion and was between quotes
//before, so we DO want to put it in output and print it.
static int	get_malloc_size(char *str)
{
	int	len;
	int	d;
	int	s;

	s = 0;
	d = 0;
	len = 0;
	count_quotes_lexer(&s, &d, str);
	len = s + d;
	if (len == 1)
		len = 0;
	return (len);
}

static char	*malloc_output(char *str, int *len)
{
	char	*output;

	*len = 0;
	*len = ft_strlen(str) - get_malloc_size(str);
	if (*len == ft_strlen(str))
		return (str);
	output = malloc(sizeof(char) * (*len) + 1);
	if (!output)
		return (ft_panic_null(MALLOC_FAILURE, __FILE__, NULL));
	return (output);
}

static void	lonely_quote(char **output, int *i, char *str)
{
	if (str[0] == '\'' && str[1] == '\0')
		(*output)[*i++] = '\'';
	else if (str[0] == '\"' && str[1] == '\0')
		(*output)[*i++] = '\"';
}

char	*trim_quotes(char *str)
{
	char	*output;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	output = malloc_output(str, &len);
	if (!output)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	lonely_quote(&output, &i, str);
	while (i < len)
	{
		if ((str[j] != '\'' && (str[j] != '\"'))
			|| (str[j] == '\'' && between_double_quotes(str, j))
			|| (str[j] == '\"' && between_single_quotes(str, j)))
			output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
	if (ft_strcmp(str, output))
		free(str);
	return (output);
}
