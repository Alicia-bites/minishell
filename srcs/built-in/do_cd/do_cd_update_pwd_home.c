/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_update_pwd_home.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:03:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 17:32:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_update_pwd_home(t_ulist **envp, t_ulist *obj, char *oldpwd)
{
	char	*pwd;
	t_ulist	*pwd_obj;
	t_ulist	*oldpwd_obj;
	t_env	*env;

	pwd = do_pwd_getpath();
	if (!pwd)
		return (ft_panic(-1, ERR_PWD));
	pwd_obj = do_export_check_exist(envp, ENV_PWD_NAME, -1);
	oldpwd_obj = do_export_check_exist(envp, ENV_OLDPWD_NAME, -1);
	if (oldpwd_obj)
		do_cd_update_env(oldpwd_obj, oldpwd);
	env = (t_env *)obj->content;
	if (pwd_obj && env)
		do_cd_update_env(pwd_obj, env->value);
	free(pwd);
	return (0);
}
