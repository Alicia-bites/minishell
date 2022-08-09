/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:51:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/09 18:30:46 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	only_double_quote_in_str(char *str)
{
	if (!ft_strcmp(str, "\"\"") || !ft_strcmp(str, "''"))
		return (1);
	return (0);
}

t_list	**do_echo_remove_quotes(t_cmd *cmd)
{
	t_list *save;

	save = *(cmd->tok_lst);
	if ((*(cmd->tok_lst))->next && 
		!ft_strcmp((*(cmd->tok_lst))->token, "echo") && (*(cmd->tok_lst))->next->toktype == TOK_ARG)
	{
		(*(cmd->tok_lst)) = (*(cmd->tok_lst))->next;
		while ((*(cmd->tok_lst)) && (*(cmd->tok_lst))->toktype == TOK_ARG)
		{
			if (!not_only_space_between_quotes((*(cmd->tok_lst))->token)
				&& !only_double_quote_in_str((*(cmd->tok_lst))->token))
					(*(cmd->tok_lst))->token = trim_quotes((*(cmd->tok_lst))->token);
			(*(cmd->tok_lst)) = (*(cmd->tok_lst))->next;
		}
	}
	*cmd->tok_lst = save;
	return (cmd->tok_lst);
}

int	do_echo(t_ulist **envp, t_cmd *cmd)
{
	int	res;
	int	index;
	
	res = 0;
	index = 1;
	index = do_echo_get_index((*cmd->tok_lst));
	if (index != 0)
	{
		cmd->tok_lst = do_echo_remove_quotes(cmd);
		ft_free_ptrptr_str(cmd->fullcmd);
		cmd_init_prop_fullcmd(*cmd->tok_lst, cmd);
		do_echo_n(envp, cmd, index);
	}
	if (!do_echo_valid_echo_n((*cmd->tok_lst)))
		res = printf("\n");
	if (res <= 0)
		return (1);
	else
		return (0);
}
