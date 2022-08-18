/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_int_expanded.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:07:46 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 17:47:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_dollar_int_expanded(void)
{
	extern long long	g_exit;
	char				*str;
	unsigned char		chr;

	chr = (unsigned char)g_exit;
	str = ft_itoa((int)chr);
	return (str);
}
