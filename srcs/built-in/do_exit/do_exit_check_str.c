/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit_check_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:15:38 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/26 19:48:10 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_exit_check_str(t_cmd *cmd, char *str)
{
	long long	i;
	unsigned long long	number;

	if (cmd->n_arg > 2)
		return (EINVAL);
	i = 0;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (EINVAL);
		i++;
	}
	number = ft_atoull(str);
	if (number >= LONG_MIN && number <= LONG_MAX)
		return (0);
	else
		return (EINVAL);
}
