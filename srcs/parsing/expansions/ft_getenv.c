/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:51:19 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *var, t_ulist *envp)
{
	t_env	*env;
	char	*output;

	env = NULL;
	while (envp)
	{
		env = (t_env *)envp->content;
		if (!ft_strcmp(env->key, var))
		{
			if (!env->value)
				return (NULL);
			output = ft_strdup(env->value);
			if (!output)
				return (ft_panic_null(-1, __func__, ERR_MALLOC));
			return (output);
		}
		envp = envp->next;
	}
	return (NULL);
}
