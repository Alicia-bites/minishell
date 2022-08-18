/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:59:05 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * display content of command node structure by casting the content to a t_cmd
 *
 * @PARAM:
 * char *cmd: string of the command written by the user
 * char *env: string of the command path from the minishell environment list
 *
 * @RETURN:
 * !NULL: address of the newly created char*
 * NULL: error
 */
char	*cmd_setpath(char *cmd, char *env)
{
	char	*path;
	size_t	len_env;
	size_t	len_env_sep;
	size_t	len_cmd;

	if (!env || !DIR_SEP)
		return (ft_panic_null(-1, __func__, ERR_NOOBJ));
	len_env = ft_strlen(env);
	len_env_sep = ft_strlen(DIR_SEP);
	len_cmd = ft_strlen(cmd);
	path = (char *)malloc(sizeof(char) * (len_env + len_env_sep
				+ len_cmd + 1));
	if (!path)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	path = ft_memmove(path, env, len_env);
	ft_memmove(path + len_env, DIR_SEP, len_env_sep);
	ft_memmove(path + len_env + len_env_sep, cmd, len_cmd);
	path[len_env + len_env_sep + len_cmd] = '\0';
	return (path);
}
