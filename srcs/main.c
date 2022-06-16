/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 18:34:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_input(void)
{
	char *str;

	while (42)
	{
		str = readline("prompt: ");
		ft_parse(str);
		// printf("%s\n", str);
		add_history(str);
	}
	return (0);
}

int	main(void)
{
	get_input();
	return (0);
}

