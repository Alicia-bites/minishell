/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env_update_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:04:25 by antho             #+#    #+#             */
/*   Updated: 2022/07/15 11:45:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_env_update_env(t_ulist *obj, char *str, int sep_pos)
{
	t_env	*env;

	printf("IN UPDATE\n");
	env = (t_env *)obj->content;
	env->fullname = str;
	env->value = &str[sep_pos];
	return (0);
}
