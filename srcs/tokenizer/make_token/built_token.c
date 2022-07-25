/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 20:18:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	go_back_to_beginning_of_list(t_list **token_list)
{
	while ((*token_list)->prev)
		(*token_list) = (*token_list)->prev;
}

static void	find_token_in_list(char *token, t_list **token_list)
{
	while (token_list)
	{
		if (!ft_strcmp(token, (*token_list)->token))
			return ;
		(*token_list) = (*token_list)->next;
	}
}

static void	check_operator_presence(char *token, t_list **token_list)
{
	find_token_in_list(token, token_list);
	if (found_operator((*token_list)->token))
		(*token_list)->toktype = TOK_NOT_OP;
	go_back_to_beginning_of_list(token_list);
}

static int	check_quote(t_chartype *input_list, int start)
{
	int	seen_quote;

	seen_quote = 0;
	if (input_list[start].character == '\''
		|| input_list[start].character == '\"')
			seen_quote = 1;
	return (seen_quote);
}

char	*trim_double_quotes(char *str)
{
	int		i;
	int		j;
	int		count_quotes;
	char	*output;
	
	i= 0;
	count_quotes = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			count_quotes++;
		i++;
	}
	output = malloc(sizeof(char) * (ft_strlen(str) - count_quotes + 1));
	if (!output)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (i <= (ft_strlen(str) - count_quotes))
	{
		if (str[j] != '\"')
			output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
	return (output);
}

char	*trim_single_quotes(char *str)
{
	int		i;
	int		j;
	int		count_quotes;
	char	*output;
	
	i= 0;
	count_quotes = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			count_quotes++;
		i++;
	}
	output = malloc(sizeof(char) * (ft_strlen(str) - count_quotes + 1));
	if (!output)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (i <= (ft_strlen(str) - count_quotes))
	{
		if (str[j] != '\'')
			output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
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
	printf("output = %s\n", output);
	return (output);
}

void	built_token(t_chartype *input_list, int start, int end,
	t_list **token_list)
{
	int			k;
	int			len;
	char		*token;
	int			seen_quote;

	seen_quote = check_quote(input_list, start);
	// remove_quotes(input_list, &start, &end);
	len = end - start;
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
	{
		ft_panic(MALLOC_FAILURE, __FILE__, NULL);
		return ;
	}
	k = 0;
	while (k < len)
		token[k++] = input_list[start++].character;
	token[k++] = '\0';
	token = trim_quotes(token);
	// printf("token = %s\n", token);
	add_token_to_list(token, token_list);
	if (seen_quote)
		check_operator_presence(token, token_list);
}
