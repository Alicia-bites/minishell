/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:48:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/21 19:06:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fd_pipe(t_ulist **cmd_lst)
{
	t_ulist	*obj;
	int		n_pipe;

	obj = *cmd_lst;
	n_pipe = ft_lst_size(cmd_lst) - 1;
	fd_pipe_pfd(obj, NULL, NULL, n_pipe);
}
