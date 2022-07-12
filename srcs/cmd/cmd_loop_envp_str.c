/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envp_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:05:01 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/12 14:22:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_loop_envp_str(char *cmd, char **envp, char *s)
{
	char	*path;
	char	**envline;
	int		i;

	path = NULL;
	envline = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], s, ft_strlen(s)) == 0)
		{
			envline = ft_split(ft_strchr(envp[i], ENV_SEP) + 1, ENV_FIELD_SEP);
			if (!envline)
			{
				ft_panic(-1, ERR_NOOBJ);
				return (NULL);
			}
			path = cmd_loop_envline(cmd, envline);
			ft_free_ptrptr_str(envline);
			if (path)
				return (path);
		}
		i++;
	}
	return (NULL);
}
