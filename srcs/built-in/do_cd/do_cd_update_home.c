/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_update_home.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:03:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 14:25:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_update_home(t_ulist **envp, t_ulist *obj)
{
	t_ulist	*pwd_obj;
	t_ulist	*oldpwd_obj;
	t_env	*env;

	pwd_obj = do_export_check_exist(envp, ENV_PWD_NAME, -1);
	oldpwd_obj = do_export_check_exist(envp, ENV_OLDPWD_NAME, -1);
	env = (t_env *)pwd_obj->content;
	if (oldpwd_obj ) // CHANGE IT BECAUSE IT IS POSSIBLE TO NOT HAVE OLD AND/OR PWDENV VAR
		do_export_update_env(oldpwd_obj, env->value, -1);
	env = (t_env *)obj->content;
	if (pwd_obj)
		do_export_update_env(pwd_obj, env->value, -1);
	return (0);
}
