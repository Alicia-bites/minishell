/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:19:28 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 12:22:27 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pwd(t_ulist **envp, t_cmd *cmd)
{
	char	*path;

	if (!cmd && cmd->n_arg == 0)
		return (ft_panic_value(-1, __FILE__, ERR_NOOBJ, EXIT_FAILURE));
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
