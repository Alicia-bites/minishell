/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:30:10 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/25 19:23:08 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_char_env(t_env *env, char **ptr, int i)
{
	char	*str;
	size_t	len_key;
	size_t	len_sep;
	size_t	len_value;

	len_key = ft_strlen(env->key);
	if (len_key <= 0)
		return (ft_panic(-1, __FILE__, ERR_NOOBJ));
	len_sep = ft_strlen("=");
	len_value = ft_strlen(env->value);
	str = (char *)malloc(sizeof(char) * (len_key + len_value
				+ len_sep + 1));
	if (!str)
		return (ft_panic(-1, __FILE__, ERR_MALLOC));
	str = ft_memmove(str, env->key, len_key);
	ft_memmove(str + len_key, "=", len_sep);
	ft_memmove(str + len_key + len_sep, env->value, len_value);
	str[len_key + len_sep + len_value] = '\0';
	ptr[i] = str;
	return (0);
}
