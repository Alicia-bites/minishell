/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_built_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:39:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/23 11:09:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Store every built-ins we must manage in a char**
char	**store_built_ins(void)
{
	char	**built_ins;

	built_ins = malloc(sizeof(char *) * (8 + 1));
	if (!built_ins)
		return (ft_panic_null(MALLOC_FAILURE, __FILE__, NULL));
	built_ins[0] = "echo";
	built_ins[1] = "echo -n";
	built_ins[2] = "cd";
	built_ins[3] = "pwd";
	built_ins[4] = "export";
	built_ins[5] = "unset";
	built_ins[6] = "env";
	built_ins[7] = "exit";
	built_ins[8] = NULL;
	return (built_ins);
}
