/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_toktype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/14 19:29:39 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is built-in a token whose name (char *token_list->token) is found in tab of
// char * built_ins (char **built_ins)
static int	is_built_in(t_list **token_list)
{
	int	i;
	char **built_ins;

	built_ins = store_built_ins();
	i = 0;
	while (i < 8)
	{
		if (!ft_strcmp((*token_list)->token, built_ins[i++]))
		{
			(*token_list)->toktype = TOK_BUILTIN;
			free(built_ins);
			return (1);
		}
	}
	free(built_ins);
	return (0);
}

int	is_combo_heredoc(t_list **token_list)
{
	if ((*token_list)->index >= 4)
	{
		if ((*token_list)->prev->prev->prev->prev->index != 0)
		{
			if ((*token_list)->prev->prev->prev->prev->toktype == TOK_DL_REDIR
				&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
				&& ((*token_list)->prev->prev->toktype == TOK_HERESEP)
				&& ((*token_list)->prev->toktype == TOK_SPACE))
					return (1);
		}
	}
	return (0);
}

// Is filename a token that is placed after a <, > or >>
// or after a <, > or >> and then a space
static int	is_filename(t_list **token_list)
{
	if (redir_token(token_list))
		return (1);		
	if (redir_space_token(token_list))
		return (1);
	else if (is_combo_heredoc(token_list))
		return (1);
	return (0);
}

// Is a heredoc separator a token that is placed after <<
// or after << and then a space
static int	is_heredoc_sep(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if ((*token_list)->prev->toktype == TOK_DL_REDIR)
			return (1);
	}
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_DL_REDIR)
				return (1);
	
	}
	return (0);
}

int	is_combo_redir(t_list **token_list)
{
	if ((*token_list)->index >= 4)
	{
		if (((*token_list)->prev->prev->prev->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->prev->prev->prev->toktype == TOK_DR_REDIR)
			&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
			&& ((*token_list)->prev->prev->toktype == TOK_FILE)
			&& ((*token_list)->prev->toktype == TOK_SPACE))
				return (1);
	}
	return (0);
}

// Is argument a token that is a $, or preceded by a space and then
// a built-in or a command
static int	is_argument(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->prev->toktype == TOK_BUILTIN
			&& (ft_strcmp((*token_list)->token, "$"))
			|| ((*token_list)->prev->prev->toktype == TOK_CMD))
			(*token_list)->toktype = TOK_ARG;
	}
	if (is_combo_redir(token_list))
		(*token_list)->toktype = TOK_ARG;
	if (is_combo_heredoc(token_list))
		(*token_list)->toktype = TOK_ARG;
	if ((*token_list)->toktype == TOK_ARG)
	{
		while (*token_list && !is_operator((*token_list)->token))
		{
			if (!only_space_in_str((*token_list)->token))
				(*token_list)->toktype = TOK_SPACE;
			else
				(*token_list)->toktype = TOK_ARG;
			*token_list = (*token_list)->next;
		}
		if ((*token_list))
			*token_list = (*token_list)->prev;
		return (1);
	}
	return (0);	
}

//check if token is preceded by <, > or >>
int	redir_token(t_list **token_list)
{
	if ((*token_list)->index >= 1)
	{
		if (((*token_list)->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->toktype == TOK_DR_REDIR))
			return (1);	
	}
	return (0);
}

//check if token is followed by <, > or >>
int	token_redir(t_list **token_list)
{
	if ((*token_list)->next)
	{
		if (((*token_list)->next->toktype == TOK_L_REDIR
			|| (*token_list)->next->toktype == TOK_R_REDIR
			|| (*token_list)->next->toktype == TOK_DR_REDIR))
			return (1);	
	}
	return (0);
}

// Check if token is preceded by a space and then <, > or >>
int	redir_space_token(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if (((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_L_REDIR)
			|| ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_R_REDIR)
			|| ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_DR_REDIR))
				return (1);		
	}
	return (0);
}

// Check if token is followed by a space and then <, > or >>
int	token_space_redir(t_list **token_list)
{
	if ((*token_list)->next && (*token_list)->next->next)
	{
		if (((*token_list)->next->toktype == TOK_SPACE
			&& (*token_list)->next->next->toktype == TOK_L_REDIR)
			|| ((*token_list)->next->toktype == TOK_SPACE
			&& (*token_list)->next->next->toktype == TOK_R_REDIR)
			|| ((*token_list)->next->toktype == TOK_SPACE
			&& (*token_list)->next->next->toktype == TOK_DR_REDIR))
				return (1);		
	}
	return (0);
}

int	is_combo_redir_when_redir_index_zero(t_list **token_list)
{
	if ((*token_list)->index >= 4)
	{
		if ((*token_list)->prev->prev->prev->prev->index == 0)
		{
			if (((*token_list)->prev->prev->prev->prev->toktype == TOK_L_REDIR
				|| (*token_list)->prev->prev->prev->prev->toktype == TOK_R_REDIR
				|| (*token_list)->prev->prev->prev->prev->toktype 
					== TOK_DR_REDIR)
				&& ((*token_list)->prev->prev->prev->toktype == TOK_SPACE)
				&& ((*token_list)->prev->prev->toktype == TOK_FILE)
				&& ((*token_list)->prev->toktype == TOK_SPACE))
					return (1);
		}
	}
	return (0);
}

int	following_pipe(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->prev->toktype == TOK_PIPE
		&& (*token_list)->prev->toktype == TOK_SPACE)
			return (1);
	}
	return (0);
}

int	cmd_heredoc(t_list **token_list)
{
	if ((*token_list)->index == 0 || following_pipe(token_list))
	{
		if (!only_space_in_str((*token_list)->next->token)
			&& is_operator((*token_list)->next->next->token) == TOK_DR_REDIR)
		return (1);
	}
	return (0);
}

int	cmd_redir(t_list **token_list)
{
	if ((*token_list)->index == 0 || following_pipe(token_list))
	{
		if (!only_space_in_str((*token_list)->next->token)
			&& is_operator((*token_list)->next->next->token) == TOK_R_REDIR
			|| is_operator((*token_list)->next->next->token) == TOK_L_REDIR
			|| is_operator((*token_list)->next->next->token) == TOK_DL_REDIR)
		return (1);
	}
	return (0);
}

void	get_toktype(t_list **token_list)
{
	t_list	*it;
	
	it = *token_list;
	while (*token_list)
	{
		if (is_built_in(token_list))
			NULL;
		else if (is_operator((*token_list)->token))
			(*token_list)->toktype = is_operator((*token_list)->token);
		else if (!only_space_in_str((*token_list)->token))
			(*token_list)->toktype = TOK_SPACE;
		else if (!only_space_in_str((*token_list)->token))
			(*token_list)->toktype = TOK_CMD;
		else if (is_filename(token_list))
			(*token_list)->toktype = TOK_FILE;
		else if (is_heredoc_sep(token_list))
			(*token_list)->toktype = TOK_HERESEP;
		else if (is_argument(token_list))
			NULL;
		else if (is_cmd(token_list))
			(*token_list)->toktype = TOK_CMD;
		if (*token_list)
			*token_list = (*token_list)->next;
	}
	*token_list = it;
}