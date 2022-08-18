/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cd_change_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:20:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_cd_change_dir(t_ulist **envp, t_cmd *cmd)
{
	char	*oldpwd;

	oldpwd = do_pwd_getpath();
	if (!oldpwd)
		return (ft_panic_value(errno, __func__, NULL, EXIT_FAILURE));
	if (chdir((const char *)cmd->fullcmd[1]) == 0)
		do_cd_update_pwd_change_dir(envp, oldpwd);
	else
	{
		free(oldpwd);
		return (ft_panic_value(errno, __func__, NULL, EXIT_FAILURE));
	}
	free(oldpwd);
	return (0);
}
