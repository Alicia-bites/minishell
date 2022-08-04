/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:57:49 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/04 10:34:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	hd_write(t_list *tok, t_cmd *cmd)
{
	char	*str;
	char	*filename;
	char	*fullcmd[2];

	filename = HD_BIN_TRUE;
	fullcmd[0] = HD_BIN_TRUE;
	fullcmd[1] = NULL;
	while (1)
	{
		str = readline(">>>>>>: ");
		printf("readline str: %s\n", str);
		if (!str || ft_strcmp(str, tok->token) == 0)
		{
			printf("FUCKING EOF\n");
			execve(filename, fullcmd, NULL);
		}
		free(str);
	}
	return (0);
}
