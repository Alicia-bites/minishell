/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_var_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:48:47 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 22:15:59 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * check the env's key and return a value of visibility
 *
 * @PARAM:
 * t_env *env: env node
 *
 * @RETURN:
 * VAR_ENV: only for env function
 * VAR_EXP: only for export function
 * VAR_ALL: for env and export function
 */
int	env_init_var_view(t_env *env)
{
	if (ft_strcmp(env->key, "_") == 0)
		return (VAR_ENV);
	else if (!env->value)
		return (VAR_EXP);
	else
		return (VAR_ALL);
}	
