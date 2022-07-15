/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_var_view.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:48:47 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/15 14:34:27 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_init_var_view(t_env *env)
{
	if (ft_strcmp(env->key, "_") == 0)
		return (VAR_ENV);
	else if (!env->value)
		return (VAR_EXP);
	else
		return (VAR_ALL);
}	
