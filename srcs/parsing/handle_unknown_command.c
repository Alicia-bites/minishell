/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unknown_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:39:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/25 16:14:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_unknown_command(t_list *token_list)
{
	static int	i = 0;
	
	if (i == 0 || i == 3)
		printf("\nCommand '%s' not found, did you mean:\n\n" \
		"  command 'echo' from deb coreutils (8.30-3ubuntu2)\n\n" \
		"Try: sudo apt install <deb name>\n\n", token_list->token);
	if (i == 1 || i == 2)
		printf("%s: command not found\n", token_list->token);
	if (i == 3)
		i = 0;
	i++;
	return (0);
}
