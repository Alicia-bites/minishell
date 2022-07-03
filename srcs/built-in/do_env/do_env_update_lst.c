/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env_update_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:31:22 by antho             #+#    #+#             */
/*   Updated: 2022/07/01 17:20:51 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* use cases:
 * env NAME1=value
 * env NAME1=value NAME2=value
 * env NAME1=value NAME2=value <command>
 */
int	do_env_update_lst(t_ulist **envp, char **str)
{
	int	i;
	int	sep_pos;
	t_ulist	*obj;
	t_env	*env;

	i = 0;
	sep_pos = 0;
	obj = NULL;
	env = NULL;
	while (str[i])
	{
		obj = *envp;
		sep_pos = ft_index((const char *)str[i], ENV_SEP);
		if (sep_pos < 0) // if env ENV_NAME=value <command> and str[i] = <command>
			break ;
		updated = 0;
		while (obj)
		{
			env = (t_env *)obj->content;
			if (ft_strncmp(env->key, str[i], sep_pos) == 0) // env->key = PATH && str[i]= "PATH=xxx" ==> res = 0
				if (do_env_update_env(obj, str[i], sep_pos) != 0)
					return (2);
				else
				{
					updated = 1;
					break ;
				}
			obj = obj->next;
		}
		if (updated == 0 && do_env_create_env(envp, str[i] != 0))
			return (3);
		i++;
	}
	return (0);
}
