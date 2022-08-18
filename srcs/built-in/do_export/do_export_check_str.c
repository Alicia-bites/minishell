/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_export_check_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:58:15 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_export_check_str(char *str, int sep_pos)
{
	size_t	len_key;
	char	*str_key;
	int		res;

	len_key = ft_strlen(str);
	if (len_key == 0)
		return (1);
	if (sep_pos >= 0)
		len_key = sep_pos;
	str_key = (char *)malloc(sizeof(char) * (len_key + 1));
	if (!str_key)
		return (ft_panic_value(-1, __func__, ERR_MALLOC,
				EXIT_FAILURE));
	ft_strlcpy(str_key, str, len_key + 1);
	if ((ft_isalpha(str[0]) || str[0] == '_')
		&& (ft_isalnum(str[len_key - 1]) || str[len_key - 1] == '_'
			|| str[len_key - 1] == '=')
		&& (!ft_strchrset_include(str_key, CHRSET_EXPORT)))
		res = 0;
	else
		res = ft_panic_value(-1, __func__, ERR_ID_VAL, EXIT_FAILURE);
	free(str_key);
	return (res);
}
