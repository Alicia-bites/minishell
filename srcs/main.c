/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/05 14:29:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		str = readline("$: ");
		if (!str)
			return (0);
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
	return (err);
}

int	main(void)
{
	get_input();
	return (0);
}
