/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:36:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/26 14:48:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_char_init(size_t len_envp)
{
	char	**ptr;
	int		i;

	ptr = (char **)malloc(sizeof(char *) * (len_envp + 1));
	if (!ptr)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	i = 0;
	while (i < len_envp)
	{
		ptr[i] = NULL;
		i++;
	}
	ptr[len_envp] = NULL;
	return (ptr);
}
