/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envp_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:05:01 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cmd_loop_envp_str(char *cmd, t_ulist **envp_lst, char *s)
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
		if (ft_strcmp(envp->key, s) == 0)
		{
			envline = cmd_loop_envp_create_envline(envp);
			if (!envline)
				return (ft_panic_null(-1, __func__, ERR_NOOBJ));
			path = cmd_loop_envline(cmd, envline);
			ft_free_ptrptr_str(envline);
			envline = NULL;
		}
		envp_node = envp_node->next;
	}
	return (path);
}
