/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:15:13 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 12:20:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_quit(int signum, siginfo_t *info, void *context)
{
	extern t_list	*token_list;
	
	(void)info;
	(void)context;
	if (signum == SIGINT)
	{
		ft_lstclear(&token_list);
		ft_lstclear_back(&token_list);
		exit(1);
	}
}
