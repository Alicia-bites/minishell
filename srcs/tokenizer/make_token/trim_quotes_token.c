/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:02:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 10:56:24 by amarchan         ###   ########.fr       */
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

static void	skip_quotes(char *str, t_dart *dart)
{
	while (str[dart->j] == '\'' && (!dart->d))
	{
		dart->s++;
		dart->j++;
	}
	while (str[dart->j] == '\"' && (!dart->s))
	{
		dart->d++;
		dart->j++;
	}
	if (str[dart->j] == '\'' && !(dart->d % 2))
	{
		dart->j++;
		dart->s++;
	}
	else if (str[dart->j] == '\"' && !(dart->s % 2))
	{
		dart->j++;
		dart->d++;
	}
}

char	*trim_quotes_token(char *str, t_list *token_list)
{
	char	*output;
	t_dart	dart;
	int		len;

	dart.s = 0;
	dart.d = 0;
	dart.j = 0;
	dart.i = 0;
	output = malloc_output(str, &len);
	while (dart.i < len)
	{
		skip_quotes(str, &dart);
		output[dart.i++] = str[dart.j++];
	}
	output[dart.i] = '\0';
	if (ft_strcmp(str, output))
		free(str);
	return (output);
}
