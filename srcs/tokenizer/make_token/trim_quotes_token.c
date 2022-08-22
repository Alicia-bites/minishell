/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:50:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/20 18:57:02 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//The only case len could be equal to 1 is when str only contains one quote.
//Since we are going to deduct get_malloc_size from ft_strlen(str) we would end
//up with len = 1 - 1 = 0. Yet, we want len to be 1 because if this quote is 
//lonly, it necessarily means it is out of an expansion and was between quotes
//before, so we DO want to put it in output and print it.
static int	quotes_to_trim(char *str)
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

static char	*malloc_output_token(char *str, int *len, int n)
{
	char	*output;

	(*len) = n + ft_strlen(str) - quotes_to_trim(str);
	if (*len == ft_strlen(str))
		return (str);
	output = malloc(sizeof(char) * (*len) + 1);
	if (!output)
		return (ft_panic_null(MALLOC_FAILURE, __func__, NULL));
	return (output);
}

static void	lonely_quote_token(char **output, int *i, char *str)
{
	if (str[0] == '\'' && str[1] == '\0')
		(*output)[(*i)++] = '\'';
	else if (str[0] == '\"' && str[1] == '\0')
		(*output)[(*i)++] = '\"';
}

char	*trim_quotes_token(char *str, t_chartype *input_list,
	int start, int end)
{
	char		*output;
	int			len;
	t_cursor	cursor;
	int			*tab;
	int			n;

	cursor.i = 0;
	cursor.k = 0;
	tab = NULL;
	if (!str)
		return (NULL);
	tab = check_quote_exp(input_list, start, end, &n);
	output = malloc_output_token(str, &len, n);
	if (!output)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	lonely_quote_token(&output, &cursor.i, str);
	while (cursor.i < len)
	{
		if (copy_ok(str, cursor.k, tab, n))
			output[cursor.i++] = str[cursor.k];
		cursor.k++;
	}
	output[cursor.i] = '\0';
	clean_up_trim_quotes_token(&str, &tab, output);
	return (output);
}
