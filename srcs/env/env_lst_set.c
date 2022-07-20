/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:19:53 by antho             #+#    #+#             */
/*   Updated: 2022/07/20 14:03:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_set(char **envp, t_ulist **env_lst)
{
	t_env	*env;
	int		i;

	i = 0;
	while (envp[i])
	{
		env = env_init(envp[i]);
		if (!env)
			return (1);
		if (!ft_lst_append(env_lst, (void *)env))
		{
			env_free((void *)env);
			return (ft_panic(-1, __FILE__, ERR_LST_APPEND));
		}
		i++;
	}
	return (0);
}
