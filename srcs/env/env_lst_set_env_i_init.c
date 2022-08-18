/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set_env_i_init.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:25:28 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 17:58:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_set_env_i_init(t_ulist **env_lst)
{
	char	*default_env[4];
	
	if (!env_lst)
		return (EXIT_FAILURE);
	default_env[0] = ENV_OLDPWD_NAME;
	default_env[1] = ENV_PATH_NAME;
	default_env[2] = ENV_PWD_NAME;
	default_env[3] = NULL;
	if (env_lst_set(default_env, env_lst))
		return (EXIT_FAILURE);
	return (0);
}
