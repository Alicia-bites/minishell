/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_hd_unset_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 15:18:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @BRIEF:
 * ignoring int signal behaviour
 * and ignoring quit signal behaviour
 *
 * @PARAM:
 * void
 *
 * @RETURN:
 * 0: ok
 * >= 0: error
 */
int	sig_hd_unset_action(void)
{
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
