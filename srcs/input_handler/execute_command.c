/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:16:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 14:16:56 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(t_list **token_list, t_ulist **cmd_list)
{
	fd_link_in_out_file(token_list, cmd_list, DIR_IN);
	fd_pipe(cmd_list);
//	ft_lst_func_lst(cmd_list, &cmd_show);
	cmd_exec(cmd_list, ft_lst_size(cmd_list));
}
