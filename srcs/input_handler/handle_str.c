/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/21 14:01:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_str(char **str, t_list **token_list, int *err, t_ulist **envp)
{
	t_ulist	**cmd_list;

	cmd_list = NULL;
	cmd_list = ft_lst_init();
	if (!cmd_list)
	{
		ft_lstclear(token_list);
		return ;
	}
	ft_parse(*str, token_list, err);
	print_lst(*token_list);
	// execute_command(token_list);
	// cmd_create_lst(*token_list, envp, cmd_list);
	// fd_infile(token_list, cmd_list, O_RDONLY);
	// fd_outfile(token_list, cmd_list, TOK_R_REDIR, O_WRONLY);
	// fd_outfile(token_list, cmd_list, TOK_DR_REDIR, O_APPEND);
	// ft_lst_func_lst(cmd_list, &cmd_show);
	ft_lstclear(token_list);
	// printf("str = %s\n", *str);
	if (is_not_empty(*str))
		add_history(*str);
	ft_lst_free(cmd_list, &cmd_free);
}
