/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 12:54:28 by amarchan         ###   ########.fr       */
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
		|| c == '$'|| c == '?')
		//|| c == '€' || (long long unsigned) c == '£' || c == '¬')
			return (1);
	return (0);
}

void	add_token_to_list(char *token, t_list **token_list)
{
	extern	t_global	*g_global;
	static int	i = 0;
	
	if (g_global->list_cleared && i > 0)
	{
		i = 0;
		g_global->list_cleared = 0;		
	}
	*token_list = create_list(token, i++, 0);
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

void	get_token(t_chartype *input_list, t_list **token_list)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (start < input_list[start].length)
	{
		*token_list = is_word(input_list, &start, &end);
		*token_list = is_space(input_list, &start, &end);
		*token_list = is_pipe(input_list, &start, &end);
		*token_list = is_s_quote(input_list, &start, &end);
		*token_list = is_d_quote(input_list, &start, &end);
		*token_list = is_l_redir(input_list, &start, &end);
		*token_list = is_r_redir(input_list, &start, &end);
		*token_list = is_dl_redir(input_list, &start, &end);
		*token_list = is_dr_redir(input_list, &start, &end);
		*token_list = is_intpoint(input_list, &start, &end);
	}
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

// //replace "$?" by the exit status of the last pipeline
// void	execute_dollarint(t_list **token_list)
// {
// 	printf("execute $?");
// }

// void	parse_dollar(t_chartype *input_list, t_list **token_list, char *token)
// {
// 	int	i;

// 	if (input_list->n_double == 0 && input_list->n_single == 0)
// 	{
// 		if (token[i] == '$' && token[i + 1] == '?')
// 			execute_dollar(token_list);
// 		if (token[i] == '$')
// 		{
// 			i++;
// 			while (token[i] == )
// 		}
		
// 	}
// }

// t_list	*get_toktype(t_chartype *input_list, t_list **token_list)
// {
// 	t_list *it;
	
// 	it = *token_list;
// 	while (it->next)
// 	{
// 		if (ft_strstr(it->token, "$"))
// 			parse_dollar(input_list, token_list, it->token);
			
// 	}
// 	print_lst(*token_list);
// }

void	tokenize(t_chartype *input_list, t_list **token_list)
{
	
	get_chartype(&input_list);
	// print_chartype(input_list);
	get_token(input_list, token_list);
	// get_toktype(input_list, token_list);
}
