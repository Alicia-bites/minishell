/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:46:30 by antho             #+#    #+#             */
/*   Updated: 2022/07/20 14:03:24 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_init_key(t_env *env, char *fullname)
{
	int		sep_pos;
	size_t	len_str;

	sep_pos = ft_index((const char *)fullname, ENV_SEP);
	if (sep_pos < 0)
		len_str = ft_strlen(fullname);
	else
		len_str = sep_pos + 1;
	env->key = (char *)malloc(sizeof(char) * (len_str + 1));
	if (!env->key)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	ft_strlcpy(env->key, (const char *)fullname, len_str + 1);
	env->key[sep_pos] = '\0';
	return (env->key);
}
