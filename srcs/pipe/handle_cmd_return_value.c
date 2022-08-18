/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd_return_value.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:33:35 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 17:40:04 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cmd_return_value(t_cmd *cmd, int res)
{
	int	err_dir;

	err_dir = 0;
	if (cmd->toktype == TOK_CMD && (res || errno) && cmd->access == -1)
	{
		err_dir = is_a_directory(cmd->tok_node->token, 1);
		if (err_dir)
			errno = err_dir;
		else 
			errno = ft_panic_value(-1, __func__, ERR_CMD_FOUND, 127);	
	}
			
	else if (cmd->toktype == TOK_CMD && (res || errno) && cmd->access != -1)
	{
		err_dir = is_a_directory(cmd->tok_node->token, 1);
		if (err_dir)
			errno = err_dir;
		else
			ft_shell_msg(errno, cmd->fullcmd[0]);
	}
}
