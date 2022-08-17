/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 11:01:39 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quote(t_chartype *input_list, int start)
{
	if (input_list[start].character == '\''
		|| input_list[start].character == '\"')
		return (1);
	else
	{
		while (is_char_word(input_list[start].character))
		{
			start++;
			if (input_list[start].character == '\''
				|| input_list[start].character == '\"')
				return (1);
		}
	}
	return (0);
}

static int	op_was_in_exp(t_chartype *input_list, int pos, char *token)
{
	if (ft_strcmp(token, "|") || ft_strcmp(token, "<") || ft_strcmp(token, ">"))
	{
		if (input_list[pos].type == CH_WORD)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	built_token(t_chartype *input_list, int start, int end,
	t_list **token_list)
{
	int			k;
	int			len;
	char		*token;
	int			seen_quote;

	seen_quote = check_quote(input_list, start);
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
	if (not_only_space_between_quotes(token) && (ft_strstr(token, "\'")
			|| ft_strstr(token, "\"")) && !is_heredoc_separator(*token_list))
		token = trim_quotes(token);
	add_token_to_list(token, token_list);
	if (token != NULL && (seen_quote
			|| op_was_in_exp(input_list, end -1, token)))
		check_operator_presence(token, token_list);
}
