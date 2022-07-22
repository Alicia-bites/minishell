/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:15 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:58:09 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_char_space(char c)
{
	if (c == ' ' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
