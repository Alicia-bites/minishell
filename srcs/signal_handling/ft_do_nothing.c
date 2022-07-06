/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_nothing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:15:13 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 14:24:04 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_do_nothing(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGQUIT)
	{
		puts("doing nothing");
		return ;
	}
	return ;
}
