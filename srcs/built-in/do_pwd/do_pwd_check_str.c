/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pwd_check_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:14:55 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/29 12:49:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_pwd_check_str(char *str)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str == 0)
		return (0);
	else if (ft_strchrset_include(str, "()"))
		return (ft_panic_value(-1, __FILE__, ERR_TOK_BRACKET, 2));
	else if (ft_strchrset_include(str, CHRSET_PWD))
		return (ft_panic_value(-1, __FILE__, ERR_OPT_INVAL, 2));
	else if (ft_strchr(str, '&'))
		return (ft_panic_value(-1, __FILE__, ERR_ID_VAL, 2));
	return (0);
}
