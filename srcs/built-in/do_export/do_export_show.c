/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:31:29 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/14 17:45:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_export_show(void *content)
{
	t_env	*env;

	if (!content)
		return ;
	env = (t_env *)content;
	printf("%s%s=\"%s\"\n", EXP_PREFIX, env->key, env->value);
}
