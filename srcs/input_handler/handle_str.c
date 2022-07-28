/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 15:44:58 by amarchan         ###   ########.fr       */
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
	t_ulist	**cmd_list;

	if (!in_ascii(*str))
	{
		*err = 0;
		return ;
	}
	cmd_list = NULL;
	cmd_list = ft_lst_init();
	if (!cmd_list)
	{
		ft_lstclear(token_list);
		return ;
	}
	ft_parse(*str, token_list, err, *envp);
	print_lst(*token_list);
	cmd_create_lst(token_list, envp, cmd_list);
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
