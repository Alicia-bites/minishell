/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_update_env.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:04:25 by antho             #+#    #+#             */
/*   Updated: 2022/07/18 12:49:35 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export_update_env(t_ulist *obj, char *str, int sep_pos)
{
	t_env	*env;

	env = (t_env *)obj->content;
	if (sep_pos < 0)
		return (0);
	if (env->value)
		free(env->value);
	env->value = ft_strdup(&str[sep_pos + 1]);
	if (env->value)
		env->var_view = VAR_ALL;
	else
	{
		ft_panic(-1, ERR_MALLOC);
		return (1);
	}
	return (0);
}
