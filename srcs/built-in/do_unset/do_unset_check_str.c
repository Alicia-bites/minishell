/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset_check_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:19:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/20 14:04:49 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_unset_check_str(char *str)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if ((ft_isalpha(str[0]) || str[0] == '_')
		&& (ft_isalnum(str[len_str - 1]) || str[len_str - 1] == '_'))
		return (0);
	else
		return (ft_panic(-1, __FILE__, ERR_UNSET_ARG));
}
