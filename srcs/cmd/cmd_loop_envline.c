/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:17:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/16 18:57:18 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_loop_envline(char *cmd, char **envline)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (envline[i])
	{
		path = cmd_setpath(cmd, envline[i]);
		if (!path)
			return (NULL);
		else if (access(path, F_OK) == 0)
		{
			if (access(path, X_OK) == 0)
				return (path);
		}
		free(path);
		path = NULL;
		i++;
	}
	return (NULL);
}
