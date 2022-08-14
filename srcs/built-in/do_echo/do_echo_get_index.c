/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo_get_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:33:28 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/14 08:18:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	invalid_arg(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] != '-')
		return (1);
	if (str[i] == '-' && str[i + 1] == '\0')
		return (1);
	if (str[i] == '-' && i + 1 < ft_strlen(str) && str[i + 1] != 'n')
		return (1);
	if (i + 1 < ft_strlen(str) && str[i] == '-' && str[i + 1] == 'n')
	{
		i++;
		while (i < ft_strlen(str) && str[i] == 'n')
		{
			if (str[i] != 'n')
				return (1);
			i++;
		}
		if (str[i] != '\0')
			return (1);
	}
	return (0);
}

int	do_echo_valid_echo_n(t_list *token_list)
{
	if (!token_list)
		return (1);
	if ((token_list)->next
		&& !ft_strcmp(token_list->token, "echo")
		&& token_list->next->toktype == TOK_ARG)
	{
		token_list = token_list->next;
		while (token_list && token_list->toktype == TOK_ARG)
		{
			if (!invalid_arg(token_list->token))
				return (1);
			else
				return (0);
			token_list = token_list->next;
		}
	}
	return (0);
}

//Return 0 if valid echo -n combination
int	do_echo_get_index(t_list *token_list)
{
	if (!token_list)
		return (0);
	if (token_list->next
		&& !ft_strcmp(token_list->token, "echo")
		&& token_list->next->toktype == TOK_ARG)
	{
		token_list = token_list->next;
		while (token_list && token_list->toktype == TOK_ARG)
		{
			if (invalid_arg(token_list->token))
				return (token_list->index);
			token_list = token_list->next;
		}
		if (!token_list)
			return (0);
	}
	return (token_list->index);
}
