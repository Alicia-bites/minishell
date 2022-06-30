/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_env_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:49:59 by antho             #+#    #+#             */
/*   Updated: 2022/06/30 15:55:55 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_env_show(void *content)
{
	t_env	*env;

	if (!content)
		return ;
	env = (t_env *)content;
	printf("%s\n", env->fullname);
}
