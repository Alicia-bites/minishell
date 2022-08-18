/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:32:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 17:40:28 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_env_lst(char **envp, t_ulist **env_lst)
{
	(void)envp;
	if (env_lst_set(envp, env_lst))
	{
		ft_lst_free(env_lst, &env_free);
		return (EXIT_FAILURE);
	}
	if (!*env_lst && env_lst_set_env_i(env_lst))
	{
		ft_lst_free(env_lst, &env_free);
		return (EXIT_FAILURE);
	}
	return (0);
}
