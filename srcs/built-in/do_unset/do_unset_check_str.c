/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_unset_check_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:19:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 11:16:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* arg must:
 * @START
 * ==> A-Z a-z _
 * @END
 * ==> A-Z a-z 0-9_
 * @NO CHARSET
 * ==> `~!@#$%^&*()-[]{}|:;\"\'
 */
int	do_unset_check_str(char *str)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str == 0)
		return (0);
	else if ((ft_isalpha(str[0]) || str[0] == '_')
		&& (ft_isalnum(str[len_str - 1]) || str[len_str - 1] == '_')
		&& !ft_strchrset_include(str, CHRSET_UNSET)
		&& !ft_strstr(str, "="))
		return (0);
	else
		return (ft_panic_value(-1, __FILE__, ERR_ID_VAL,
				EXIT_FAILURE));
}
