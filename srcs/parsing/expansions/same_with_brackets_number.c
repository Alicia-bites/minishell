/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_with_brackets_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:56:46 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:37:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	same_with_brackets_zero(char *str, int i)
{
	if (i + 3 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '{'
		&& str[i + 2] == '0' && str[i + 3] == '}')
		return (1);
	return (0);
}

int	same_with_brackets_number(char *str, int i)
{
	if (i + 3 < ft_strlen(str) && str[i] == '$' && str[i + 1] == '{'
		&& ft_isdigit(str[i + 2]) && str[i + 3] == '}')
		return (1);
	return (0);
}
