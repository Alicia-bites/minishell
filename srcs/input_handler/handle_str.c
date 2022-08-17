/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/17 15:56:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	in_ascii(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] >= 127)
			return (0);
		i++;
	}
	return (1);
}

void	handle_str(char **str, t_list **token_list, int *err, t_ulist **envp)
{
	extern t_global	g_msl;
	t_ulist	**cmd_list;

	if (!in_ascii(*str))
	{
		*err = 0;
		return ;
	}
	cmd_list = NULL;
	cmd_list = ft_lst_init();
	if (is_not_empty(*str))
		add_history(*str);
	if (!cmd_list)
	{
		ft_lstclear(token_list);
		return ;
	}
	if (ft_parse(*str, token_list, err, *envp))
	{
		g_msl.exit = 2; //TODO: get ft_parse return value to set this variable correctly
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
//	print_lst(*token_list);
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
//	if (hd_link(token_list, cmd_list))
//	{
//		ft_lstclear(token_list);
//		ft_lst_free(cmd_list, &cmd_free);
//		return ;
//	}
//	fd_link_in_out_file(token_list, cmd_list, DIR_IN);
//	fd_pipe(cmd_list);
//	cmd_exec(cmd_list, ft_lst_size(cmd_list));
	ft_lst_func_lst(cmd_list, &cmd_show);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	if (hd_tokfile(token_list, cmd_list, envp))
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
	ft_lst_func_lst(cmd_list, &cmd_show);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	fd_init(token_list, cmd_list);
	ft_lst_func_lst(cmd_list, &cmd_show);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	// TEST: > file99 wc < file1 < file2 | < file3 cat | < file5 ls < file6
	// TES: echo Salut > file1 | >> file1 echo Toto | < file1 wc < file3
	fd_pipe(cmd_list);
	cmd_exec(cmd_list, ft_lst_size(cmd_list));
	ft_lstclear(token_list);
	ft_lst_free(cmd_list, &cmd_free);
}
