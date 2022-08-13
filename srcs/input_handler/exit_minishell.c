/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/13 15:22:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_list **token_list, int *err, t_ulist **envp)
{
	extern t_global	g_msl;

	rl_clear_history();
	ft_lstclear(token_list);
	ft_lst_free(envp, &env_free);
	printf("exit\n");
	exit(g_msl.exit);
}
