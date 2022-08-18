/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_varname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:49:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 13:01:52 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*malloc_varname(char *str, int start, int end)
{
	char	*new_str;
	int		i;
	int		len;

	len = end - start;
	new_str = malloc(sizeof(char) * end + 1);
	if (!new_str)
		return (ft_panic_null(MALLOC_FAILURE, __func__, NULL));
	i = 0;
	while (i <= len - 1)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}
