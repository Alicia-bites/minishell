/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:15:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 11:23:04 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_exec(t_list **token_list, t_ulist	**cmd_list, t_ulist **envp)
{
	if (cmd_check_tok_lst(token_list))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return (1);
	}
	if (cmd_create_lst(token_list, envp, cmd_list))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return (1);
	}
	if (hd_tokfile(token_list, cmd_list, envp))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return (1);
	}
	fd_init(token_list, cmd_list);
	fd_pipe(cmd_list);
	return (0);
}
