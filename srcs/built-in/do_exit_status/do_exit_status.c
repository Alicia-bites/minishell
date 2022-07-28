/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:44:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/27 20:20:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit_status(t_cmd *cmd)
{
	extern t_global	global;
	unsigned char	chr;

	if (cmd->n_arg > 1)
		return (ft_panic(EINVAL, __FILE__, NULL));
	chr = (unsigned char)global.exit_status;
	printf("%d\n", (int)chr);
	return (0);
}
