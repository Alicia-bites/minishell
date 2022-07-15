/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:39:13 by antho             #+#    #+#             */
/*   Updated: 2022/07/15 11:43:37 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_show(void *content)
{
	t_env	*env;

	if (!content)
		return ;
	env = (t_env *)content;
	printf("fullname: %s\n", env->fullname);
	if (env->key)
		printf("key: %s\n", env->key);
	if (env->value)
		printf("value: %s\n", env->value);
	printf("var_view: %d\n", env->var_view);
	printf("%s\n", SEP_P);
}
