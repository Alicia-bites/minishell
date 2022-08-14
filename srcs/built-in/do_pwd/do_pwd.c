/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:19:28 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/14 08:30:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *
 */
int	do_pwd(t_cmd *cmd)
{
	char	*path;
	int		internal_error;

	internal_error = 0;
	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
	if (cmd->n_arg >= 2)
	{
		if (cmd->fullcmd[1][0] == ARG_DEL)
			return (ft_panic_value(-1, __FILE__, ERR_OPT_INVAL, 2));
		internal_error = do_pwd_loop_arg(&cmd->fullcmd[1]);
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
