/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:13:23 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 22:54:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * malloc and populate a char** to store every minishell env node content
 * from minishell environment list by concatenating the key and the value
 * example:
 * env->key = USER
 * env->value = smbash
 * char[i] = USER=smbash
 * the char **envp will be used during execve to send the latest update
 * of the environment list to the command
 *
 * @PARAM:
 * t_ulist **env_lst: minishell environment lst
 *
 * @RETURN:
 * !NULL: address of the newly created char **envp
 * NULL: error
 */
char	**env_char_set(t_ulist **env_lst)
{
	char	**envp;
	size_t	len_env_lst;

	len_env_lst = env_char_size(env_lst);
	envp = env_char_init(len_env_lst);
	if (!envp)
		return (NULL);
	if (env_char_loop_env_lst(*env_lst, envp))
	{
		ft_free_ptrptr_str(envp);
		return (NULL);
	}
	return (envp);
}
