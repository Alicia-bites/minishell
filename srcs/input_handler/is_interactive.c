/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_interactive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:19:07 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 18:13:09 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_interactive(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDERR_FILENO));
}