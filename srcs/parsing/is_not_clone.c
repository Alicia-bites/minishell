/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:12:56 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/23 11:11:15 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_not_clone(char *str)
{
	static char	*prev_str = NULL;

	if (ft_strcmp(prev_str, str) == 0)
	{
		prev_str = str;
		return (0);
	}
	prev_str = str;
	return (1);
}
