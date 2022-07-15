/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_loop_envp_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:05:01 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/15 15:06:09 by abarrier         ###   ########.fr       */
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
	while (envp_node)
	{
		envp = (t_env *)envp_node->content;
		//printf("**%s** envp ptr = %p\n)", __FILE__, envp);
		//printf("**%s** envp ptr = %p\t envp->fullname = %s\n)", __FILE__, envp, envp->fullname);
		if (ft_strncmp(envp->fullname, s, ft_strlen(s)) == 0)
		{
			if (!envp->value)
				envline = ft_split("", ENV_FIELD_SEP);
			else
				envline = ft_split(envp->value, ENV_FIELD_SEP);

			if (!envline)
			{
				ft_panic(-1, ERR_NOOBJ);
				return (NULL);
			}
			path = cmd_loop_envline(cmd, envline);
			ft_free_ptrptr_str(envline);
			envline = NULL;
			if (path)
				return (path);
		}
		envp_node = envp_node->next;
	}
	return (NULL);
}
