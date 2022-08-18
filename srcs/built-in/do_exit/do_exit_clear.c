/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_exit_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:53:00 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	seen_pipe(t_list *tok_node)
{
	if (!tok_node)
		return (0);
	while (tok_node)
	{
		if (!ft_strcmp(tok_node->token, "|"))
			return (1);
		tok_node = tok_node->prev;
	}
	return (0);
}

void	do_exit_clear(t_ulist **envp, t_ulist **cmd_lst, t_cmd *cmd,
		char *err_msg)
{
	extern t_global	g_msl;

	if (!seen_pipe(cmd->tok_node))
		printf("exit\n");
	if (err_msg)
		ft_panic(-1, __func__, ERR_ARG_NUM);
	rl_clear_history();
	ft_lstclear(cmd->tok_lst);
	ft_lst_free(envp, &env_free);
	ft_lst_free(cmd_lst, &cmd_free);
	exit(g_msl.exit);
}
