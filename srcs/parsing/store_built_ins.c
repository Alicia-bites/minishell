/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_built_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:39:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 18:10:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Store every built-ins we must manage in a char**
char	**store_built_ins(void)
{
	char **built_ins;
	
	built_ins = malloc(sizeof(char*) * 9 + 1);
	if (!built_ins)
		ft_panic(MALLOC_FAILURE, 0);
	built_ins[0] = "echo";
	built_ins[1] = "echo -n";
	built_ins[2] = "cd";
	built_ins[3] = "pwd";
	built_ins[4] = "export";
	built_ins[5] = "unset";
	built_ins[6] = "env";
	built_ins[7] = "exit";
	built_ins[8] = "\0";
	return (built_ins);
}