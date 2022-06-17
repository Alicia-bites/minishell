/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:08:03 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 18:33:38 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Place commmands and arguments in a linked list
void	sort_inputs(char **inputs)
{
	int		i;
	t_list	*inputs_lst;
	char	**built_ins;

	i = 0;
	built_ins = store_built_ins();
	//FOR DEBUG
	// while (i < 7)
	// 	printf("%s\n", built_ins[i++]);
	// puts("----------------------------------");
	// i = 0;
	//END
	while (inputs[i])
	{
		if (!ft_strcmp(inputs[i], "echo")
			&& !ft_strcmp(inputs[i + 1], "-n"))
			{
				inputs[i] = "echo -n";
				inputs_lst = create_list(inputs[i], i);
				i += 2;
			}
		inputs_lst = create_list(inputs[i], i);
		i++;
	}
	// print_lst(inputs_lst);
	read_command(inputs_lst, built_ins);
}