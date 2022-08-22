/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hd_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:21:57 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/22 14:31:52 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_hd_fd(t_list **token_list, t_ulist **cmd_list, t_ulist **env_list)
{
	extern long long	g_exit;
	int					sentinel;

	if (hd_tokfile(token_list, cmd_list, env_list))
		return (1);
	sentinel = fd_init(token_list, cmd_list);
	if (ft_lst_size(cmd_list) == 0 && sentinel > 0)
	{
		g_exit = EXIT_FAILURE;
		return (1);
	}
	return (0);
}
