/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing_follows_follar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:21:56 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 15:22:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nothing_follows_follar(char *str, int i)
{
	if (!str)
		return (0);
	if (str[i] == '$' && (str[i + 1] == '\0' || ft_isspace(str[i + 1])))
		return (1);
	return (0);
}
