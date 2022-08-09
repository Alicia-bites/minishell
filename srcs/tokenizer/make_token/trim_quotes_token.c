/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:02:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:38 by amarchan         ###   ########.fr       */
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
// 	printf("s = %d\n", s);
	// printf("d = %d\n", d);
	len = s + d;
	return (len);	
}

static char *malloc_output(char *str, int *len)
{
	char *output;
	
	*len = 0;
	*len = ft_strlen(str) - get_malloc_size(str);
	if (*len == ft_strlen(str))
		return (str);
	output = malloc(sizeof(char) * (*len) + 1);
	if (!output)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return (NULL);
	}
	return (output);
}

static int	is_heredoc_delimiter(t_list *token_list, char *str)
{
	t_list	*iterator;

	if (!token_list)
		return (0);
	iterator = token_list;
	while (iterator && strcmp(iterator->token, str))
		iterator = iterator->next;
	if (iterator && iterator->prev && !ft_strcmp(iterator->prev->token, "<<"))
			return (1);
	return (0);
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

char *trim_quotes_token(char *str, t_list *token_list)
{
	char	*output;
	t_dart	dart;
	int		len;
	
	dart.s = 0;
	dart.d = 0;
	dart.j = 0;
	dart.i = 0;
	output = malloc_output(str, &len);
	while (dart.i <= len)
	{
		if (!is_heredoc_delimiter(token_list, str))
			skip_quotes(str, &dart);
		output[dart.i++] = str[dart.j++];
	}
	output[dart.i] = '\0';
	return (output);
}