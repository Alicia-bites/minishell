/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env_update_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:04:25 by antho             #+#    #+#             */
/*   Updated: 2022/07/01 17:12:35 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_env_update_env(t_ulist *obj, char *str, int sep_pos)
{
	t_env	*env;

	printf("IN UPDATE\n");
	env = (t_env *)obj->content;
	env->old_fullname = env->fullname;
	env->old_value = env->value;
	env->fullname = str;
	env->value = &str[sep_pos];
	return (0);
}
