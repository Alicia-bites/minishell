/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_check_exist.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:17:50 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 10:48:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ulist	*do_export_check_exist(t_ulist **envp, char *str, int sep_pos)
{
	t_ulist	*obj;
	t_env	*env;
	size_t	len_key;

	obj = *envp;
	env = NULL;
	if (sep_pos >= 0)
		len_key = sep_pos;
	else
		len_key = ft_strlen(str);
	while (obj)
	{
		env = (t_env *)obj->content;
		if (ft_strncmp(env->key, str, len_key) == 0)
			return (obj);
		obj = obj->next;
	}
	return (NULL);
}