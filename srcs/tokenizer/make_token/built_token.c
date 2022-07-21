/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/21 17:17:27 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void check_quotes_bn(t_chartype *input_list, int *start, int *len)
// {
// 	if (*start == 0 || input_list[*start + 1].character == '\0')
// 	{
		
// 	}
// 	if (input_list[*start - 1].character == '"'
// 		&& input_list[*start].character == '\\'
// 		&& (input_list[*start + 1].character == '"'
// 		|| input_list[*start + 1].character == '\\'))
// 		{
// 			if (input_list[*start - 1].character == '"'
// 				&& input_list[*start].character == '\\'
// 				&& input_list[*start + 1].character == '"'
// 				&& input_list[*start + 2].character != '"')
// 				(*start)--; 
// 			(*start)++;
// 			(*len)--;			
// 		}
// }

void	check_operator_presence(t_list **token_list)
{
	if (found_operator((*token_list)->token))
	{
		puts("FOUND_OP");
		(*token_list)->toktype = TOK_ARG;
	}
}

int	check_quote(t_chartype *input_list, int start)
{
	int	seen_quote;
	
	seen_quote = 0;
	if (input_list[start].character == '\''
		|| input_list[start].character == '\"')
		{
			puts("FOUND_QUOTE");
			seen_quote = 1;
		}
			
	return (seen_quote);
}

void built_token(t_chartype *input_list, int start, int end, t_list **token_list)
{
	int			k;
	int			len;
	char 		*token;
	int			seen_quote;

	seen_quote = check_quote(input_list, start);
	remove_quotes(input_list, &start, &end);
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
	add_token_to_list(token, token_list);
	if (seen_quote)
		check_operator_presence(token_list);
}
