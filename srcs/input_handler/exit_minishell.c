/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 18:58:38 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(t_list **token_list, int *err, t_ulist **envp)
{
	rl_clear_history();
	ft_lstclear(token_list);
	ft_lst_func_lst(envp, &env_free);
	printf("err = %d\n", *err);
	printf("exit");
	exit(*err);
}
