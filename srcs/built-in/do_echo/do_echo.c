/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:51:54 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/29 14:25:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	do_echo_remove_quotes(t_list **token_list)
{
	t_list *save;

	save = *token_list;
	if ((*token_list)->next && 
		!ft_strcmp((*token_list)->token, "echo") && (*token_list)->next->toktype == TOK_ARG)
	{
		(*token_list) = (*token_list)->next;
		while ((*token_list) && (*token_list)->toktype == TOK_ARG)
		{
			if (not_only_space_between_quotes((*token_list)->token))
				trim_quotes((*token_list)->token);
			(*token_list) = (*token_list)->next;
		}
	}
	*token_list = save;
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
		do_echo_remove_quotes(cmd->tok_lst);
		do_echo_n(envp, cmd, index);		
	}
	if (!do_echo_valid_echo_n((*cmd->tok_lst)))
		res = printf("\n");
	if (res <= 0)
		return (1);
	else
		return (0);
}
