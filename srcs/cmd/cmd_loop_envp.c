/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:05:01 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 12:00:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_loop_envp(char *cmd, t_ulist **envp_lst)
{
	t_ulist	*envp_node;
	t_env	*envp;
	char	*path;
	char	**envline;

	envp_node = *envp_lst;
	envp = NULL;
	path = NULL;
	envline = NULL;
	while (envp_node && !path)
	{
		envp = (t_env *)envp_node->content;
		envline = cmd_loop_envp_create_envline(envp);
		if (!envline)
			return (ft_panic_null(-1, ERR_NOOBJ));
		path = cmd_loop_envline(cmd, envline);
		ft_free_ptrptr_str(envline);
		envline = NULL;
		envp_node = envp_node->next;
	}
	return (path);
}
