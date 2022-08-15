/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:02:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 18:45:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

// static void	skip_quotes(char *str, t_dart *dart)
// {
// 	if (str[dart->j] == '\'' && !between_double_quotes(str, dart->j))
// 		dart->s++;
// 	else if (str[dart->j] == '\"' && !between_single_quotes(str, dart->i))
// 		dart->d++;
// }

char	*trim_quotes(char *str)
{
	char	*output;
	int		len;
	int		i;
	int		j;

	i= 0;
	j = 0;
	output = malloc_output(str, &len);
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
