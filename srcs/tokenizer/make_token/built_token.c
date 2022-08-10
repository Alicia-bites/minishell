/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/09 17:02:06 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quote(t_chartype *input_list, int start)
{
	int	seen_quote;

	seen_quote = 0;
	if (input_list[start].character == '\''
		|| input_list[start].character == '\"')
			seen_quote = 1;
	return (seen_quote);
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
	if (not_only_space_between_quotes(token))
		token = trim_quotes_token(token, *token_list);
	add_token_to_list(token, token_list);
	if (seen_quote && token != NULL)
		check_operator_presence(token, token_list);
}
