/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_hd_unset_action.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:56:06 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 14:41:46 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
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
	signal(SIGINT, &sig_program_prompt_back_hd);
	return (0);
}
