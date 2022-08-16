/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_update_pwd_home.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:03:36 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/16 17:55:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * update PWD and OLDPWD environment variable value
 *
 * @PARAM:
 * t_ulist **envp: environment variable list
 * t_ulist *obj: HOME env node
 * char *oldpwd: string of the old pwd value
 *
 * @RETURN (int)
 * 0: ok
 * >= 0: error
 */
int	do_cd_update_pwd_home(t_ulist **envp, t_ulist *obj, char *oldpwd)
{
	char	*pwd;
	t_ulist	*pwd_obj;
	t_ulist	*oldpwd_obj;
	t_env	*env;

	pwd = do_pwd_getpath();
	if (!pwd)
		return (ft_panic(-1, __FILE__, ERR_PWD));
	pwd_obj = do_export_check_exist(envp, ENV_PWD_NAME, -1);
	oldpwd_obj = do_export_check_exist(envp, ENV_OLDPWD_NAME, -1);
	if (oldpwd_obj && oldpwd)
		do_cd_update_env(oldpwd_obj, oldpwd);
	env = (t_env *)obj->content;
	if (pwd_obj && env)
		do_cd_update_env(pwd_obj, env->value);
	free(pwd);
	return (0);
}
