/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:46:30 by antho             #+#    #+#             */
/*   Updated: 2022/06/28 19:33:09 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_init_key(t_env *env, char *fullname)
{
	int		sep_pos;

	sep_pos = ft_index((const char *)fullname, ENV_SEP);
	if (sep_pos < 0)
	{
		ft_panic(-1, "ERROR TO BE DEFINED");
		return (NULL);
	}
	env->key = (char *)malloc(sizeof(char) * (sep_pos + 1));
	if (!env->key)
	{
		ft_panic(-1, ERR_MALLOC);
		return (NULL);
	}
	ft_strlcpy(env->key, (const char *)fullname, (size_t)sep_pos + 1);
	env->key[sep_pos] = '\0';
	return (env->key);
}
