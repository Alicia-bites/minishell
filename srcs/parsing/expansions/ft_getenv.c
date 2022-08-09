/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:51:19 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/31 15:51:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *var, t_ulist *envp)
{
	t_env	*env;

	env = NULL;
	while (envp)
	{
		env = (t_env *)envp->content;
		if (!ft_strcmp(env->key, var))
		{
			if (!env->value)
				return (NULL);
			return (env->value);
		}
		envp = envp->next;
	}
	return (NULL);
}
