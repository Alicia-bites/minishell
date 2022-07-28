/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:19:28 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 17:51:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *
 */
int	do_pwd(t_ulist **envp, t_cmd *cmd)
{
	char	*path;
	int		internal_error;

	internal_error = 0;
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	if (cmd->n_arg >= 2)
	{
		if (cmd->fullcmd[1][0] == ARG_DEL)
			return (ft_panic_value(-1, __FILE__, ERR_INVALID_OPT,
					2));
		internal_error = do_pwd_loop_arg(envp, &cmd->fullcmd[1]);
		if (internal_error)
			return (internal_error);
	}
	path = do_pwd_getpath();
	if (path)
	{
		printf("%s\n", path);
		free(path);
	}
	else
		return (ft_panic_value(-1, __FILE__, ERR_MALLOC, EXIT_FAILURE));
	return (0);
}
