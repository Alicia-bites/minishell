/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:32:33 by antho             #+#    #+#             */
/*   Updated: 2022/08/11 23:07:41 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * loop through each env node to display its properties
 *
 * @PARAM:
 * t_ulist **list: minishell environment list
 *
 * @RETURN:
 * N/A
 */
void	env_lst_show(t_ulist **list)
{
	ft_lst_func_lst(list, &env_show);
}
