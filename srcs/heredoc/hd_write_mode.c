/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 09:37:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 09:33:30 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_write_mode(t_list *tok)
{
	if (ft_strchrset_include(tok->token, HD_CHRSET))
		return (HD_NO_EXP);
	else
		return (HD_EXP);
}
