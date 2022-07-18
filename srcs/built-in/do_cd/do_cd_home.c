/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:44:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 17:57:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_home(t_ulist **envp)
{
	t_ulist	*obj;
	t_env	*env;
	char	*oldpwd;

	obj = do_export_check_exist(envp, ENV_HOME_NAME, -1);
	oldpwd = NULL;
	if (obj)
	{
		env = (t_env *)obj->content;
		if (env->value == NULL || env->value[0] == '\0')
			return (0);
		oldpwd = do_pwd_getpath();
		if (!oldpwd)
			return (ft_panic(errno, NULL));
		if (chdir((const char *)env->value) == 0)
			do_cd_update_pwd_home(envp, obj, oldpwd);
		else
		{
			free(oldpwd);
			return (ft_panic(errno, NULL));
		}
		free(oldpwd);
	}
	else
	{
		ft_panic(-1, ERR_NOHOME);
		return (1);
	}
	return (0);
}
