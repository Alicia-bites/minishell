/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:12:22 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 16:48:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_quote(char *str)
{
	if (str)
		if (ft_strstr(str, "\'") || ft_strstr(str, "\""))
			return (1);
	return (0);
}

int	found_operator(char *str)
{
	if (str)
		if (ft_strstr(str, "|") || ft_strstr(str, ">>")
			|| ft_strstr(str, "<<") || ft_strstr(str, "<")
			|| ft_strstr(str, ">"))
			return (1);
	return (0);
}
