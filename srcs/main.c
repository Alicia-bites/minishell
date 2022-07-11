/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 17:39:57 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global global;

int	get_input(void)
{
	char	*str;
	int		err;
	t_list	*token_list;
	
	token_list = NULL;
	str = NULL;
	err = 0;
	while (42)
	{
		global.readline = 1;
		while (global.readline)
		{
			global.readline = 0;
			str = readline("$: ");
			break ;
		}
		if (!str)
		{
			rl_clear_history();
			ft_lstclear(&token_list);
			return (0);
		}
		if (str[0] != 0)
		{
			err = ft_parse(str, &token_list);
			// print_lst(token_list);
			// execute_command(token_list);
			ft_lstclear(&token_list);
			// printf("token_list (main) = %p\n", token_list);
			if (is_not_clone(str) && is_not_empty(str))
				add_history(str);
		}
	}
	rl_clear_history();
	printf("err = %d\n", err);
	return (err);
}

int	main(void)
{
	if (ft_set_sigaction() == -1)
		printf("Setting up sigaction failed.\n");
	get_input();
	return (0);
}
