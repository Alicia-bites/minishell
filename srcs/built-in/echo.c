/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:56:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 18:18:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_echo(char *str)
{
	printf("%s\n", str);
	return (0);
}

int	do_echo_n(char *str)
{
	printf("%s", str);
	return (0);
}