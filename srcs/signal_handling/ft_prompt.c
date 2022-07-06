/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:24:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/06 14:17:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_prompt(int signum, siginfo_t *info, void *context)
{
	extern t_list	*token_list;

	(void)info;
	(void)context;
	if (signum == SIGINT)
	{
		ft_lstclear(&token_list);
		ft_lstclear_back(&token_list);
		puts("shaking the bush here boss");
		get_input();
	}
}