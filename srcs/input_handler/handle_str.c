/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 11:20:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_up_ft_parse(int *err, t_list **token_list, t_ulist **cmd_list)
{
	extern t_global	g_msl;
	
	g_msl.exit = *err;
	ft_lstclear(token_list);
	ft_lst_free(cmd_list, &cmd_free);
	return ;
}

void	handle_str(char **str, t_list **token_list, int *err, t_ulist **envp)
{
	extern t_global	g_msl;
	t_ulist	**cmd_list;

	if (!in_ascii(*str))
		return ;
	cmd_list = NULL;
	cmd_list = ft_lst_init();
	if (is_not_empty(*str))
		add_history(*str);
	if (!cmd_list)
		return ;
	if (ft_parse(*str, token_list, err, *envp))
		return (clean_up_ft_parse(err, token_list, cmd_list));
	// print_lst(*token_list);
	if (!*token_list)
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
	if (cmd_check_tok_lst(token_list)) // LOOP THROUGH EVERY TOKEN TO CHECK IF REDIR TOKEN HAVE A NEXT TOKEN FILE
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
	if(cmd_create_lst(token_list, envp, cmd_list))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
//	ft_lst_func_lst(cmd_list, &cmd_show);
	if (hd_link(token_list, cmd_list))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
	fd_link_in_out_file(token_list, cmd_list, DIR_IN);
	fd_pipe(cmd_list);
//	ft_lst_func_lst(cmd_list, &cmd_show);
	cmd_exec(cmd_list, ft_lst_size(cmd_list));
	ft_lstclear(token_list);
	ft_lst_free(cmd_list, &cmd_free);
}
