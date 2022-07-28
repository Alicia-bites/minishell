/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:13:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 10:58:53 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_not_empty(char *str)
{
	if (str == 0 || !ft_strcmp(" ", str) || !ft_strcmp("\f", str)
		|| !ft_strcmp("\n", str) || !ft_strcmp("\r", str)
		|| !ft_strcmp("\t", str) || !ft_strcmp("\v", str))
		return (0);
	return (1);
}
