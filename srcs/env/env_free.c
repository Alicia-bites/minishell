/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:11:36 by antho             #+#    #+#             */
/*   Updated: 2022/06/28 20:04:21 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_free(void *content)
{
	t_env	*env;
	
	if (!content)
		return ;
	env = (t_env *)content;
	if (env->key)
	{
		free(env->key);
		env->key = NULL;
	}
	free(env);
	env = NULL;
}
