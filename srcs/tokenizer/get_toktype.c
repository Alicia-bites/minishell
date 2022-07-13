/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_toktype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/13 14:21:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int	is_filename(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->toktype == TOK_L_REDIR
			|| (*token_list)->prev->toktype == TOK_R_REDIR
			|| (*token_list)->prev->toktype == TOK_DR_REDIR)
			return (1);		
	}
	if ((*token_list)->index >= 3)
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

static int	is_heredoc_sep(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->toktype == TOK_DL_REDIR)
			return (1);
	}
	if ((*token_list)->index >= 3)
	{
		if ((*token_list)->prev->toktype == TOK_SPACE
			&& (*token_list)->prev->prev->toktype == TOK_DL_REDIR)
				return (1);
	
	}
	return (0);
}

static int	is_argument(t_list **token_list)
{
	if ((*token_list)->index >= 2)
	{
		if ((*token_list)->prev->prev->toktype == TOK_BUILTIN
			&& (ft_strcmp((*token_list)->token, "$"))
			|| ((*token_list)->prev->prev->toktype == TOK_CMD))
			(*token_list)->toktype = TOK_ARG;
	}
	else if ((*token_list)->index >= 3)
	{
		if (!(ft_strcmp((*token_list)->prev->token, "$")
			&& (*token_list)->prev->prev->toktype == TOK_BUILTIN)
			|| (*token_list)->prev->toktype == TOK_CMD)
			(*token_list)->toktype = TOK_ARG;
	}
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

int	is_cmd(t_list **token_list)
{
	if ((redir_token(token_list)
		|| redir_space_token(token_list))
		&& (token_redir(token_list))
		|| token_space_redir(token_list))
		return (0);
	return (1);
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