/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_check_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:17:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 14:42:21 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ulist	*do_export_check_exist(t_ulist **env_lst, char *str, int sep_pos)
{
	t_ulist	*obj;
	t_env	*env;
	size_t	len_key;

	obj = *env_lst;
	env = NULL;
	len_key = do_export_check_exist_len_key(str, sep_pos);
	while (obj)
	{
		env = (t_env *)obj->content;
		if (sep_pos > 0)
		{
			if (ft_strncmp(env->key, str, len_key) == 0
				&& str[len_key] == ENV_SEP
				&& env->key[len_key] == '\0')
				return (obj);
		}
		else
		{
			if (ft_strcmp(env->key, str) == 0)
				return (obj);
		}
		obj = obj->next;
	}
	return (NULL);
}
