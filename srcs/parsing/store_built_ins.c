/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_built_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:39:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 09:11:42 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Store every built-ins we must manage in a char**
char	**store_built_ins(void)
{
	char	**built_ins;

	built_ins = malloc(sizeof(char *) * (9 + 1));
	if (!built_ins)
		return (ft_panic_null(MALLOC_FAILURE, __FILE__, NULL));
	built_ins[0] = BUILT_ECHO;
	built_ins[1] = BUILT_ECHO_N;
	built_ins[2] = BUILT_CD;
	built_ins[3] = BUILT_PWD;
	built_ins[4] = BUILT_EXPORT;
	built_ins[5] = BUILT_UNSET;
	built_ins[6] = BUILT_ENV;
	built_ins[7] = BUILT_EXIT;
	built_ins[8] = BUILT_EXIT_STATUS;
	built_ins[9] = NULL;
	return (built_ins);
}
