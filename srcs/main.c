/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 18:34:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_global	*g_global;

int	get_input(void)
{
	char	*str;
	t_list	*token_list;
	
	g_global = malloc(sizeof(t_global));
	if (!g_global)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (0);
	}
	while (42)
	{
		str = readline("$: ");
		if (!str)
			return (0);
		if (str[0] != 0)
		{
			// printf("%s\n", str);
			ft_parse(str, &token_list);
			print_lst(token_list);
			// execute_command(token_list);
			ft_lstclear(&token_list);
			g_global->list_cleared = 1;
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
