/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:36:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/11 22:50:58 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * malloc char **envp sized according to env node which have visibility
 * var_view VAR_ALL or VAR_ENV
 *
 * @PARAM:
 * size_t len_env_lst: size of the minishell environment list listing
 * only env node which have visibility var_view VAR_ALL or VAR_ENV
 *
 * @RETURN:
 * !NULL: address of the newly created char **envp to be used for execve
 * NULL: error
 */
char	**env_char_init(size_t len_env_lst)
{
	char	**envp;
	int		i;

	envp = (char **)malloc(sizeof(char *) * (len_env_lst + 1));
	if (!envp)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	i = 0;
	while (i < len_env_lst)
	{
		envp[i] = NULL;
		i++;
	}
	envp[len_env_lst] = NULL;
	return (envp);
}
