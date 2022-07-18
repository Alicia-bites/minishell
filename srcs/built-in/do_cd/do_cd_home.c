/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_home.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:44:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 14:19:57 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_home(t_ulist **envp)
{
	t_ulist	*obj;
	t_env	*env;
	int	res;

	obj = do_export_check_exist(envp, ENV_HOME_NAME, -1);
	res = 0;
	if (obj)
	{
		env = (t_env *)obj->content;
		if (env->value == NULL || env->value[0] == '\0')
			return (0);
		res = chdir((const char *)env->value);
		if (res == 0)
			do_cd_update_home(envp, obj);
		else
			return (ft_panic(errno, NULL));
	}
	else
	{
		ft_panic(-1, ERR_NOHOME);
		return (1);
	}
	return (0);
}
