/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_check_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:58:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/18 12:50:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export_check_str(char *str)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if ((ft_isalpha(str[0]) || str[0] == '_')
		&& (ft_isalnum(str[len_str - 1]) || str[len_str - 1] == '_'
			|| str[len_str - 1] == '='))
		return (0);
	ft_panic(-1, ERR_EXP_ARG);
	return (1);
}
