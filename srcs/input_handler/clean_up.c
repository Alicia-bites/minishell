/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:13:31 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 14:52:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_up_ft_parse(int *err, t_list **token_list, t_ulist **cmd_list)
{
	extern long long	g_exit;

	g_exit = *err;
	ft_lstclear(token_list);
	ft_lst_free(cmd_list, &cmd_free);
}

void	clean_up(t_list **token_list, t_ulist **cmd_list)
{
	ft_lstclear(token_list);
	ft_lst_free(cmd_list, &cmd_free);
}
