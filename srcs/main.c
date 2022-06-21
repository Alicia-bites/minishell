/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 11:08:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_not_clone(char *str)
{
	static char	*prev_str = NULL;
	
	if (ft_strcmp(prev_str, str) == 0)
	{
		prev_str = str;
		return (0);
	}
	prev_str = str;
	return (1);
}

int	is_not_empty(char *str)
{
	// printf("str_2 = %s\n", str);
	if (str == 0 || !ft_strcmp(" ", str) || !ft_strcmp("\f", str)
		|| !ft_strcmp("\n", str) || !ft_strcmp("\r", str)
		|| !ft_strcmp("\t", str) || !ft_strcmp("\v", str))	
		{
			puts("hey you");
			return (0);			
		}
	return (1);
}

int	get_input(void)
{
	char *str;

	while (42)
	{
		str = readline("prompt: ");
		if (!str)
			return (0);
		if (str[0] != 0)
		{
			// printf("%s\n", str);
			ft_parse(str);
			if (is_not_clone(str) && is_not_empty(str))
				add_history(str);
		}
	}
	return (0);
}

int	main(void)
{
	get_input();
	return (0);
}

