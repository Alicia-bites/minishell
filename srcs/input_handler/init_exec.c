/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:15:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 14:27:17 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_exec(t_list **token_list, t_ulist	**cmd_list, t_ulist **env_list)
{
	if (cmd_check_tok_lst(token_list))
	{
		clean_up(token_list, cmd_list);
		return (1);
	}
	if (cmd_create_lst(token_list, env_list, cmd_list))
	{
		clean_up(token_list, cmd_list);
		return (1);
	}
	if (init_hd_fd(token_list, cmd_list, env_list))
	{
		clean_up(token_list, cmd_list);
		return (1);
	}
	fd_pipe(cmd_list);
	return (0);
}
