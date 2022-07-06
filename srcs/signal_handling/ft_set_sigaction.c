/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:14:53 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 12:17:11 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_set_sigaction(void)
{
	struct sigaction	action;

	action.sa_sigaction = ft_quit;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGINT);
	if (sigaction(SIGINT, &action, 0) == -1)
		return (-1);
	return (0);
}