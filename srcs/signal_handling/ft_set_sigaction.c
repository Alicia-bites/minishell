/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_sigaction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:14:53 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 14:21:30 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_set_sigaction(void)
{
	struct sigaction	action;
	
	//do nothing
	action.sa_sigaction = ft_do_nothing;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGQUIT);
	if (sigaction(SIGQUIT, &action, 0) == -1)
		return (-1);
	//give the prompt back
	action.sa_sigaction = ft_prompt;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGINT);
	if (sigaction(SIGINT, &action, 0) == -1)
		return (-1);
	return (0);
}