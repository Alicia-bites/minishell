/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:31:29 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/15 14:36:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_export_show(void *content)
{
	t_env	*env;

	if (!content)
		return ;
	env = (t_env *)content;
	if (env->var_view == VAR_ALL || env->var_view == VAR_EXP)
	{
		if (!env->value)
			printf("%s%s\n", EXP_PREFIX, env->key);
		else
			printf("%s%s=\"%s\"\n", EXP_PREFIX, env->key, env->value);
	}
}
