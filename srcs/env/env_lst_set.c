/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:19:53 by antho             #+#    #+#             */
/*   Updated: 2022/08/15 09:11:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * populate the environment list by using the char **envp from the main
 * function
 *
 * @PARAM:
 * char **envp: original environment list
 * t_ulist **env_lst: minishell environment list
 *
 * @RETURN:
 * 0: ok
 * >= 0: error
 */
int	env_lst_set(char **envp, t_ulist **env_lst)
{
	t_env	*env;
	int		i;

	if (!envp)
		return (ft_panic(-1, __FILE__, ERR_NOOBJ));
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
