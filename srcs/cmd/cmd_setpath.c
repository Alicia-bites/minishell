/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:59:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 14:00:07 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_setpath(char *cmd, char *env)
{
	char	*path;
	size_t	len_env;
	size_t	len_env_sep;
	size_t	len_cmd;

	if (!env || !DIR_SEP)
		return (ft_panic_null(-1, __FILE__, ERR_NOOBJ));
	len_env = ft_strlen(env);
	len_env_sep = ft_strlen(DIR_SEP);
	len_cmd = ft_strlen(cmd);
	path = (char *)malloc(sizeof(char) * (len_env + len_env_sep
				+ len_cmd + 1));
	if (!path)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	path = ft_memmove(path, env, len_env);
	ft_memmove(path + len_env, DIR_SEP, len_env_sep);
	ft_memmove(path + len_env + len_env_sep, cmd, len_cmd);
	path[len_env + len_env_sep + len_cmd] = '\0';
	return (path);
}
