/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/28 12:44:24 by amarchan         ###   ########.fr       */
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
	static int	i = 0;
	
	if (!*token_list)
		i = 0;
	*token_list = create_list(token, i++, 0);
}

void	remove_squotes(t_chartype *input_list, int *start, int *end)
{
	int	quotes;
	int	i;

	quotes = 0;
	i = *start;
	while (i < *end)
	{
		if (input_list[i].character == '\'')
		{
			quotes++;
		}
		i++;
	}
	if (quotes == 2)
	{
		(*start) += 1;
		(*end)   -= 1;
	}
}

void	remove_dquotes(t_chartype *input_list, int *start, int *end)
{
	int	quotes;
	int	i;

	quotes = 0;
	i = *start;
	while (i < *end)
	{
		if (input_list[i].character == '\"')
		{
			quotes++;
		}
		i++;
	}
	if (quotes == 2)
	{
		(*start) += 1;
		(*end)   -= 1;
	}
}

void	remove_quotes(t_chartype *input_list, int *start, int *end)
{
	remove_squotes(input_list, start, end);
	remove_dquotes(input_list, start, end);
}

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
		ft_panic(MALLOC_FAILURE, 0);
		return ;
	}
	k = 0;
	while (k < len)
		token[k++] = input_list[start++].character;
	token[k++] = '\0';
	start = end;
	add_token_to_list(token, token_list);
}

void	get_token(t_chartype *input_list, t_list **token_list)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (start < input_list[start].length)
	{
		is_word(input_list, &start, &end, token_list);
		is_space(input_list, &start, &end, token_list);
		is_pipe(input_list, &start, &end, token_list);
		is_s_quote(input_list, &start, &end, token_list);
		is_d_quote(input_list, &start, &end, token_list);
		is_l_redir(input_list, &start, &end, token_list);
		is_r_redir(input_list, &start, &end, token_list);
		is_dl_redir(input_list, &start, &end, token_list);
		is_dr_redir(input_list, &start, &end, token_list);
		is_bn(input_list, &start, &end, token_list);
		// *token_list = is_intpoint(input_list, &start, &end);
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
		if ((*input_list)[i].character == '\n')
			(*input_list)[i].type = CH_BN;
		
		i++;
	}
	// print_chartype(*input_list);
	return (i);
}

e_toktype	is_operator(char *str)
{
	if (str)
	{
		if (!ft_strstr(str, "|"))
			return (TOK_PIPE);
		if (!ft_strstr(str, "<"))
			return (TOK_L_REDIR);
		if (!ft_strstr(str, ">"))
			return (TOK_R_REDIR);
		if (!ft_strstr(str, "<<"))
			return (TOK_DL_REDIR);
		if (!ft_strstr(str, ">>"))
			return (TOK_DR_REDIR);
	}
	return (0);
}

int	is_char_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	get_toktype(t_chartype *input_list, t_list **token_list)
{
	t_list	*it;
	int		i;
	int		cmd_notfound;
	char 	**built_ins;
	
	it = *token_list;
	i = 0;
	cmd_notfound = 0;
	built_ins = store_built_ins();
	while (*token_list)
	{
		while (i < 8)
		{
			if (!ft_strcmp((*token_list)->token, built_ins[i]))
			{
				(*token_list)->toktype = TOK_BUILTIN;
			}
			else if (is_char_space((*token_list)->token[0]))
			{
				(*token_list)->toktype = TOK_SPACE;
			}
			//aller chercher cette fonction dans pipex
			// else if (ft_iscommand((*token_list)->token))
			// {
				// (*token_list)->toktype = "command";
			// }
			// else if ((*token_list)->prev->toktype == TOK_BUILTIN
				// || (*token_list)->prev->toktype == TOK_CMD)
			// {
				// (*token_list)->toktype = TOK_ARG;				
			// }
			else if (is_operator((*token_list)->token))
			{
				(*token_list)->toktype = is_operator((*token_list)->token);				
			}
			i++;
		}
		*token_list = (*token_list)->next;
	}
	*token_list = it;
	// print_lst(*token_list);
}

void	tokenize(t_chartype *input_list, t_list **token_list)
{
	
	get_chartype(&input_list);
	// print_chartype(input_list);
	get_token(input_list, token_list);
	// print_lst(*token_list);
	get_toktype(input_list, token_list);
}
