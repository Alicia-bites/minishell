/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 12:39:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_commands_finder(char **inputs_list)
{
	int	i;

	i = 0;
	while (inputs_list[i])
	{
		if ()
	}
}

// Parse arguments and return inputs_list(s)
char	*ft_parse(char *str)
{	
	char **inputs_list;
	int	i;
	
	i = 0;
	ft_strip(str);
	inputs_list = ft_split(str, 32);
// 	while (inputs_list[i])
		// printf("%s\n", inputs_list[i++]);
	commands = ft_commands_finder(inputs_list);
	if (!ft_strcmp(inputs_list[0], "echo"))
	{
		while ()
		ft_echo(inputs_list[1], 0);		
	}
	else if (!ft_strcmp(inputs_list[0], "echo -n"))
		ft_echo(inputs_list[1], 1);
	return (0);
}