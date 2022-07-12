/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:05:01 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 14:20:57 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_loop_envp(char *cmd, char **envp)
{
	char	*path;
	char	**envline;
	int		i;

	path = NULL;
	envline = NULL;
	i = 0;
	while (envp[i])
	{
		envline = ft_split(ft_strchr(envp[i], ENV_SEP) + 1, ENV_FIELD_SEP);
		if (!envline)
		{
			ft_panic(-1, ERR_NOOBJ);
			return (NULL);
		}
		path = cmd_loop_envline(cmd, envline);
		ft_free_ptrptr_str(envline);
		envline = NULL;
		if (path)
			return (path);
		i++;
	}
	return (NULL);
}
