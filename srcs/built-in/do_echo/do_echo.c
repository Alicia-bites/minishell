/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:51:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 14:37:05 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_double_quote_in_str(char *str)
{
	if (!ft_strcmp(str, "\"\"") || !ft_strcmp(str, "''"))
		return (1);
	return (0);
}

t_list	*do_echo_remove_quotes(t_cmd *cmd)
{
	t_list	*save;

	save = cmd->tok_node;
	if (cmd->tok_node->next
		&& !ft_strcmp(cmd->tok_node->token, "echo")
		&& (cmd->tok_node->next->toktype == TOK_ARG))
	{
		cmd->tok_node = cmd->tok_node->next;
		while (cmd->tok_node && cmd->tok_node->toktype == TOK_ARG)
		{
			if (!not_only_space_between_quotes(cmd->tok_node->token)
				&& !only_double_quote_in_str(cmd->tok_node->token))
					cmd->tok_node->token = trim_quotes(cmd->tok_node->token);
			cmd->tok_node = cmd->tok_node->next;
		}
	}
	cmd->tok_node = save;
	return (cmd->tok_node);
}

int	do_echo(t_ulist **envp, t_cmd *cmd)
{
	int	res;
	int	index;

	res = 0;
	index = 1;
	index = do_echo_get_index((cmd->tok_node));
	if (index != 0)
	{
		cmd->tok_node = do_echo_remove_quotes(cmd);
		ft_free_ptrptr_str(cmd->fullcmd);
		cmd_init_prop_fullcmd(cmd->tok_node, cmd);
		res += do_echo_n(envp, cmd, index);
	}
	if (!do_echo_valid_echo_n((cmd->tok_node)))
		res += printf("\n");
	if (res <= 0)
		return (1);
	else
		return (0);
}
