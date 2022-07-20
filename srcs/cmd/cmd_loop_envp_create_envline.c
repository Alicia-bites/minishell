/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envp_create_envline.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:42:41 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 11:55:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cmd_loop_envp_create_envline(t_env *envp)
{
	char	**envline;

	if (!envp->value)
		envline = ft_split("", ENV_FIELD_SEP);
	else
		envline = ft_split(envp->value, ENV_FIELD_SEP);
	return (envline);
}
