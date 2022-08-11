/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:53:15 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_list **token_list, int *err, t_ulist **envp)
{
	extern t_global	g_msl;

	rl_clear_history();
	ft_lstclear(token_list);
	ft_lst_free(envp, &env_free);
	//printf("err = %d\n", *err);
	printf("err = %lld\n", g_msl.exit);
	printf("exit");
	exit(g_msl.exit);
}
