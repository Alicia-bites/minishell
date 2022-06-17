/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/17 18:31:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int is_char_word(char c)
{
	if (ft_isalnum(c) || c == ';' || c == ',' || c == ':' || c == '.'
		|| c == '_' || c == '-')
			return (1);
	return (0);
}

static void	print_chartype(t_chartype *input_list)
{
	int	i;
	
	i = 0;
	while (input_list[i].character)
	{
		printf("%c -> %d\n", input_list[i].character, input_list[i].type);
		i++;		
	}	
}

int	get_chartype(t_chartype **input_list)
{
	int	i;

	i = 0;
	while ((*input_list)[i].character)
	{
		if (is_char_word((*input_list)[i].character))
			(*input_list)[i].type = CH_WORD;
		if (ft_isspace((*input_list)[i].character))
			(*input_list)[i].type = CH_SPACE;
		if ((*input_list)[i].character == '|')
			(*input_list)[i].type = CH_PIPE;
		if ((*input_list)[i].character == 39)
			(*input_list)[i].type = CH_S_QUOTE;
		if ((*input_list)[i].character == '"')
			(*input_list)[i].type = CH_D_QUOTE;
		if ((*input_list)[i].character == '$')
			(*input_list)[i].type = CH_DOLLAR;
		if ((*input_list)[i].character == '<')
			(*input_list)[i].type = CH_L_REDIR;
		if ((*input_list)[i].character == '>')
			(*input_list)[i].type = CH_R_REDIR;
		if ((*input_list)[i].character == '=')
			(*input_list)[i].type = CH_EQUAL;
		if ((*input_list)[i].character == '?')
			(*input_list)[i].type = CH_INTPOINT;
		i++;
	}
	// print_chartype(*input_list);
	return (i);
}

char *built_token(t_chartype *input_list, int i, int j)
{
	int	len;
	int	k;
	char *token;
	
	len = i + j;
	printf("len = %d\n", len);
	printf("i = %d\n", i);
	printf("j = %d\n", j);
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	k = 0;
	while (k < len)
	{
		token[k] = input_list[i].character;
		i++;
		k++;
	}
	printf("%s\n", token);
	return (0);
}

int	get_token(t_chartype *input_list)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input_list[i].character)
	{
		if (input_list[i].type == CH_WORD)
		{
			built_token(input_list, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	tokenize(t_chartype *input_list)
{
	get_chartype(&input_list);
	print_chartype(input_list);
	get_token(input_list);
	return (0);
}
