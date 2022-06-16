/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 12:23:57 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_input(char *str)
{
	char *command;

	while (42)
	{
		str = readline("prompt: ");
		command = ft_parse(str);
		// printf("%s\n", str);
		add_history(str);
	}
	return (str);
}

int	main(void)
{
	char *str;

	str = "";
	str = get_input(str);
	return (0);
}
