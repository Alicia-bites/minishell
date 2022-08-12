/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_int_expanded.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:07:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 14:34:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_dollar_int_expanded(void)
{
	extern t_global	g_msl;
	char			*str;
	unsigned char	chr;

	chr = (unsigned char)g_msl.exit;
	str = ft_itoa((int)chr);
	printf("** %s **TEST ANTHO: %s\n", __FILE__, str);
	return (str);
}
