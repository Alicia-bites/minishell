/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset_update_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:15:48 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/11 10:40:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_unset_update_lst(t_ulist **envp, char **str)
{
	int	i;
	t_ulist	*obj;
	t_env	*env;
	int	updated;

	i = 0;
	obj = NULL;
	env = NULL;
	while (str[i])
	{
		obj = *envp;
		updated = 0;
		while (obj && updated == 0)
		{
			env = (t_env *)obj->content;
			if (ft_strncmp(env->key, str[i], ft_strlen(str[i])) == 0) // env->key = PATH && str[i]= "PATH" ==> res = 0
			{
				if (ft_lst_delbyobj(obj, &env_free) == NULL)
					return (2);
				else
					updated = 1;
			}
			obj = obj->next;
		}
		i++;
	}
	return (0);
}
