/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_update_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:31:22 by antho             #+#    #+#             */
/*   Updated: 2022/07/15 14:25:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* use cases:
 * export NAME1		==> Add the variable but with NULL address on the value
 * env NAME1=value
 * env NAME1=value NAME2=value x=y
 */
int	do_export_update_lst(t_ulist **envp, char **str)
{
	int	i;
	int	sep_pos;
	t_ulist	*obj;
	t_env	*env;
	int	updated;

	i = 0;
	sep_pos = 0;
	obj = NULL;
	env = NULL;
	while (str[i])
	{
		obj = *envp;
		sep_pos = ft_index((const char *)str[i], ENV_SEP);
		updated = 0;
		while (obj && updated == 0)
		{
			env = (t_env *)obj->content;
			if (ft_strncmp(env->key, str[i], sep_pos) == 0) // env->key = PATH && str[i]= "PATH=xxx" ==> res = 0
			{
				if (do_export_update_env(obj, str[i], sep_pos) != 0)
					return (2);
				else
					updated = 1;
			}
			obj = obj->next;
		}
		if (updated == 0)
			do_export_create_env(envp, str[i]);
		i++;
	}
	return (0);
}
