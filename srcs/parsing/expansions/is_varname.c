/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_varname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:54:12 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 17:30:07 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_varname(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}
