/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:59:00 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 16:23:36 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_echo(char **token)
{
	char	*str;
	int		i;

	str = "echo";
	(*token) = malloc(sizeof(char) * (4 + 1));
	i = 0;
	while (i < 4)
	{
		(*token)[i] = str[i];
		i++;
	}
	(*token)[4] = '\0';
}

void	built_echo(t_list **token_list, int space)
{
	char *token;
	
	if (!space)
		copy_echo(&token);
	else
		token = "echo -n";
	add_token_to_list(token, token_list);
}