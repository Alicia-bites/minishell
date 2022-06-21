/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 17:31:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int is_char_word(char c)
{
	if (ft_isalnum(c) || c == ';' || c == ',' || c == ':' || c == '.'
		|| c == '_' || c == '-' || c == '!' || c == '=' || c == '~'
		|| c == '#' || c == '+' || c == '-' || c == '*' || c == '&'
		|| c == '`' || c == '^' || c == '|' || c == '\\' || c == '/'
		|| c == '@' || c == '_' || c == ')' || c == '(' || c == '%'
		|| c == '$')
		// || c == '?'|| c == '€' || (long long unsigned) c == '£' || c == '¬')
			return (1);
	return (0);
}

void	add_token_to_list(char *token, t_list **token_list)
{
	static int	i = 0;
	
	*token_list = create_list(token, i++, 0);
	// print_lst(*token_list);
}

t_list *built_token(t_chartype *input_list, int start, int end)
{
	int			len;
	int			k;
	char 		*token;
	t_list		*token_list;
	
	len = end - start;
	// printf("start = %d\n", start);
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	k = 0;
	while (k < len)
	{
		// printf("char = %c\n", input_list[start].character);
		token[k] = input_list[start].character;
		start++;
		k++;
	}
	token[k++] = '\0';
	start = end;
	// printf("end = %d\n", end);
	// printf("token = %s\n", token);
	add_token_to_list(token, &token_list);
	return (token_list);
}

t_list	*get_token(t_chartype *input_list)
{
	int	start;
	int	end;
	t_list	*token_list;

	start = 0;
	end = 0;
	while (start < input_list[start].length)
	{
		token_list = is_word(input_list, &start, &end);
		token_list = is_space(input_list, &start, &end);
		token_list = is_pipe(input_list, &start, &end);
		token_list = is_s_quote(input_list, &start, &end);
		token_list = is_d_quote(input_list, &start, &end);
		token_list = is_l_redir(input_list, &start, &end);
		token_list = is_r_redir(input_list, &start, &end);
		token_list = is_dl_redir(input_list, &start, &end);
		token_list = is_dr_redir(input_list, &start, &end);
		token_list = is_intpoint(input_list, &start, &end);
	}
	return (token_list);
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
		if ((*input_list)[i].character == '\'' && (*input_list)->n_single == 1)
			(*input_list)[i].type = CH_WORD;
		else if ((*input_list)[i].character == '\'' && (*input_list)->n_single > 1)
			(*input_list)[i].type = CH_S_QUOTE;
		if ((*input_list)[i].character == '"' && (*input_list)->n_double == 1)
			(*input_list)[i].type = CH_WORD;
		else if ((*input_list)[i].character == '"' && (*input_list)->n_double > 1)
			(*input_list)[i].type = CH_D_QUOTE;
		if ((*input_list)[i].character == '<')
			(*input_list)[i].type = CH_L_REDIR;
		if ((*input_list)[i].character == '>')
			(*input_list)[i].type = CH_R_REDIR;
		i++;
	}
	// print_chartype(*input_list);
	return (i);
}

t_list	*get_toktype(t_list *token_list)
{
	print_lst(token_list);
	return (token_list);
}

int	tokenize(t_chartype *input_list)
{
	t_list	*token_list;
	
	get_chartype(&input_list);
	// print_chartype(input_list);
	token_list = get_token(input_list);
	token_list = get_toktype(token_list);
	return (0);
}
