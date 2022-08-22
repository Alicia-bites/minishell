/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 18:41:48 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_str(char **str, t_list **token_list, int *err,
		t_ulist **env_list)
{
	t_ulist	**cmd_list;

	if (!in_ascii(*str))
		return ;
	cmd_list = NULL;
	cmd_list = ft_lst_init();
	add_history(*str);
	if (!cmd_list)
		return ;
	if (ft_parse(*str, token_list, err, *env_list))
		return (clean_up_ft_parse(err, token_list, cmd_list));
	if (!*token_list)
	{
		ft_lstclear(token_list);
		ft_lst_free(cmd_list, &cmd_free);
		return ;
	}
	if (init_exec(token_list, cmd_list, env_list))
		return ;
	if (ft_lst_size(cmd_list) > 0)
		cmd_exec(cmd_list, ft_lst_size(cmd_list));
	clean_up(token_list, cmd_list);
}
