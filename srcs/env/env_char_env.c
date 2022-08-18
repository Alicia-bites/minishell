/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:30:10 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * malloc a string according to the size of the env->key and env->value
 * then copy and concatenate the content into the envp at a specific index 
 * example:
 * env->key = USER
 * env->value = smbash
 * envp[i] = USER=smbash
 *
 * @PARAM:
 * t_env *env: env node
 * char **envp: environment string including the key and the value to be
 * send for execve
 * int i: index in the envp
 *
 * @RETURN:
 * 0: ok
 * > 0: error
 */
int	env_char_env(t_env *env, char **envp, int i)
{
	size_t	len_key;
	size_t	len_value;

	len_key = ft_strlen(env->key);
	if (len_key <= 0)
		return (ft_panic(-1, __func__, ERR_NOOBJ));
	len_value = ft_strlen(env->value);
	envp[i] = (char *)malloc(sizeof(char) * (len_key + 1 + len_value + 1));
	if (!envp[i])
		return (ft_panic(-1, __func__, ERR_MALLOC));
	envp[i] = ft_memmove(envp[i], env->key, len_key);
	ft_memmove(envp[i] + len_key, "=", 1);
	ft_memmove(envp[i] + len_key + 1, env->value, len_value);
	envp[i][len_key + 1 + len_value] = '\0';
	return (0);
}
