/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:58 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/20 13:46:13 by abarrier         ###   ########.fr       */
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

void built_token(t_chartype *input_list, int start, int end, t_list **token_list)
{
	int			len;
	int			k;
	char 		*token;

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
	{
		// check_quotes_bn(input_list, &start, &len);
		token[k++] = input_list[start++].character;
	}
	token[k++] = '\0';
	add_token_to_list(token, token_list);
}
