/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 18:58:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_str(char **str, t_list **token_list, int *err, t_ulist **envp)
{
	t_ulist	**cmd_list;

	cmd_list = NULL;
	cmd_list = ft_lst_init();
//	cmd_list = NULL;;
	if (!cmd_list)
	{
		ft_lstclear(token_list);
		return ;
	}
	if(ft_parse(*str, token_list, err, *envp))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
//	print_lst(*token_list);
	if(!*token_list)
	{
		ft_panic(-1, __FILE__, ERR_NOTOK);
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
	fd_link_in_out_file(token_list, cmd_list, DIR_IN);
	fd_pipe(cmd_list);
	//ft_lst_func_lst(cmd_list, &cmd_show);
	cmd_execution(cmd_list, ft_lst_size(cmd_list));
	ft_lstclear(token_list);
	// printf("str = %s\n", *str);
	if (is_not_empty(*str))
		add_history(*str);
	ft_lst_free(cmd_list, &cmd_free);
}
