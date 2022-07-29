/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:13:23 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/26 16:49:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_char_set(t_ulist **envp)
{
	char	**ptr;
	size_t	len_envp;

	len_envp = env_char_size(envp);
	ptr = env_char_init(len_envp);
	if (!ptr)
		return (NULL);
	if (env_char_loop_envp(*envp, len_envp, ptr))
	{
		ft_free_ptrptr_str(ptr);
		return (NULL);
	}
	return (ptr);
}