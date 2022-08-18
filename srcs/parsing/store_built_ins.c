/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_built_ins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:39:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Store every built-ins we must manage in a char**
char	**store_built_ins(void)
{
	char	**built_ins;

	built_ins = malloc(sizeof(char *) * (8 + 1));
	if (!built_ins)
		return (ft_panic_null(MALLOC_FAILURE, __func__, NULL));
	built_ins[0] = BUILT_ECHO;
	built_ins[1] = BUILT_CD;
	built_ins[2] = BUILT_PWD;
	built_ins[3] = BUILT_EXPORT;
	built_ins[4] = BUILT_UNSET;
	built_ins[5] = BUILT_ENV;
	built_ins[6] = BUILT_EXIT;
	built_ins[7] = BUILT_EXIT_STATUS;
	built_ins[8] = NULL;
	return (built_ins);
}
