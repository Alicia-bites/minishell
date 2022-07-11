/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_cmd_setpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:59:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/20 11:33:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ppx_cmd_setpath(char *cmd, char *env)
{
	char	*path;
	size_t	len_env;
	size_t	len_env_sep;
	size_t	len_cmd;

	if (!env || !DIR_SEP)
	{
		ft_error("cdm_setpath", "env/DIR_SEP", 0, ERR_NOOBJ);
		return (NULL);
	}
	len_env = ft_strlen(env);
	len_env_sep = ft_strlen(DIR_SEP);
	len_cmd = ft_strlen(cmd);
	path = (char *)malloc(sizeof(char) * (len_env + len_env_sep
				+ len_cmd + 1));
	if (!path)
	{
		ft_error("cdm_setpath", "path", 0, ERR_MALLOC);
		return (NULL);
	}
	path = ft_memmove(path, env, len_env);
	ft_memmove(path + len_env, DIR_SEP, len_env_sep);
	ft_memmove(path + len_env + len_env_sep, cmd, len_cmd);
	path[len_env + len_env_sep + len_cmd] = '\0';
	return (path);
}
