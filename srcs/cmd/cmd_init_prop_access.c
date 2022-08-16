/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_prop_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:21:29 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/16 19:02:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_init_prop_access(t_cmd *cmd)
{
	if (cmd->toktype == TOK_BUILTIN)
		cmd->access = 0;
}
