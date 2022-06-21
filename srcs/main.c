/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 11:14:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_input(void)
{
	char	*str;

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
