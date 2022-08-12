/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_int_expanded.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:07:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/12 13:50:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_dollar_int_expanded(void)
{
	extern t_global	g_msl;
	char			*str;
	unsigned char		chr;

	chr = (unsigned char)g_msl.exit;
	str = ft_itoa((int)chr);
	return (str);
}
