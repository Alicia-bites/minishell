/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:44:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/03 13:55:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit_status(t_cmd *cmd)
{
	extern long long	g_msl_exit;
	unsigned char		chr;

	if (cmd->n_arg > 1)
		return (ft_panic(EINVAL, __FILE__, NULL));
	chr = (unsigned char)g_msl_exit;
	printf("%d\n", (int)chr);
	return (0);
}
