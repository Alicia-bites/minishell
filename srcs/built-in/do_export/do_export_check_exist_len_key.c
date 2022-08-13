/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_check_exist_len_key.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:08:43 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 15:14:48 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	do_export_check_exist_len_key(char *str, int sep_pos)
{
	if (sep_pos >= 0)
		return (sep_pos);
	else
		return (ft_strlen(str));
}
