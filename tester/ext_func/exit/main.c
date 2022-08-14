/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/26 17:41:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define SEP_P "####################"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	int	i;
	char	*err_msg;

	i = 0;
	err_msg = NULL;
	while (i <= 255)
	{
		err_msg = strerror(i);
		printf("error code: %d\tmsg: %s\n", i, err_msg);
		i++;
		printf("%s\n", SEP_P);
	}
	return (1);
}
