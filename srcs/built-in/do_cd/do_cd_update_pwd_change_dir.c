/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_update_pwd_change_dir.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:50:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/29 16:04:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @BRIEF:
 * update PWD and OLDPWD environment variable value
 *
 * @PARAM:
 * t_ulist **envp: environment variable list
 * t_ulist *obj: HOME env node
 * char *oldpwd: string of the old pwd value
 *
 * @RETURN (int)
 * 0: Ok
 *  >= 0: error
 */
int	do_cd_update_pwd_change_dir(t_ulist **envp, char *oldpwd)
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
	if (oldpwd_obj)
		do_cd_update_env(oldpwd_obj, oldpwd);
	if (pwd_obj)
		do_cd_update_env(pwd_obj, pwd);
	free(pwd);
	return (0);
}
