/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_char_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:36:20 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/25 19:15:19 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_char_init(size_t len_envp)
{
	char	**ptr;

	ptr = (char **)malloc(sizeof(char *) * (len_envp + 1));
	if (!ptr)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	ft_bzero((void *)ptr, len_envp);
	ptr[len_envp] = NULL;
}
