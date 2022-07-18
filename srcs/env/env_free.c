/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:11:36 by antho             #+#    #+#             */
/*   Updated: 2022/07/15 13:53:33 by abarrier         ###   ########.fr       */
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
	if (env->value)
	{
		free(env->value);
		env->value = NULL;
	}
	free(env);
	env = NULL;
}
