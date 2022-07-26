/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:30:10 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/26 14:47:50 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_char_env(t_env *env, char **ptr, int i)
{
	size_t	len_key;
	size_t	len_value;

	len_key = ft_strlen(env->key);
	if (len_key <= 0)
		return (ft_panic(-1, __FILE__, ERR_NOOBJ));
	len_value = ft_strlen(env->value);
	ptr[i] = (char *)malloc(sizeof(char) * (len_key + 1 + len_value + 1));
	if (!ptr[i])
		return (ft_panic(-1, __FILE__, ERR_MALLOC));
	ptr[i] = ft_memmove(ptr[i], env->key, len_key);
	ft_memmove(ptr[i] + len_key, "=", 1);
	ft_memmove(ptr[i] + len_key + 1, env->value, len_value);
	ptr[i][len_key + 1 + len_value] = '\0';
	return (0);
}
