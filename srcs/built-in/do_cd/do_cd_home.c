/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:44:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/16 17:47:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_home(t_ulist **envp)
{
	t_ulist	*obj;
	t_env	*env;
	char	*oldpwd;

	obj = do_export_check_exist(envp, ENV_HOME_NAME, -1);
	if (obj)
	{
		env = (t_env *)obj->content;
		if (env->value == NULL || env->value[0] == '\0')
			return (0);
		oldpwd = do_pwd_getpath();
		if (!oldpwd)
			oldpwd = ft_getenv(ENV_OLDPWD_NAME, *envp);
		if (chdir((const char *)env->value) == 0)
			do_cd_update_pwd_home(envp, obj, oldpwd);
		else
		{
			free(oldpwd);
			return (ft_panic(errno, __FILE__, NULL));
		}
		free(oldpwd);
		return (0);
	}
	else
		return (ft_panic(-1, __FILE__, ERR_NOHOME));
}
