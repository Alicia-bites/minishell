/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:23:36 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 14:57:08 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_panic(int errcode, char *str)
{
	printf("Error\n");
	if (errcode == MALLOC_FAILURE)
		printf("Memory allocation failed.\n");
	if (errcode == WRONG_CMD)
		printf("%s: command not found.\n", str);
	else
		(void)*str;
	exit(errcode);
}