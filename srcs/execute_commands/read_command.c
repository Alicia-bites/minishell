/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:14:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/20 12:53:28 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Find in built_ins what command is invoked
int	read_command(t_list *inputs_lst, char **built_ins)
{
	t_list	*it;
	int		i;
	int		cmd_notfound;
	
	it = inputs_lst;
	i = 0;
	cmd_notfound = 0;
	while (it)
	{
		while (i < 8)
		{
			if (!ft_strcmp(it->token, built_ins[i]))
			{
				if (it->next)
					execute_command(it->next->token, i);				
				else
					execute_command("", i);
			}
			i++;
		}
		it = it->next;
	}
	if (i == 0)
		handle_unknown_command(inputs_lst);
	return (0);
}