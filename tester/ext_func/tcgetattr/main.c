/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/15 10:28:15 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>

#define SEP_P "####################"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	int	i;
	int	res;
	int	custo_fd;
	struct termios *termios_p;

	if (argc == 1)
		return (0);
	i = 1;
	res = -1;
	custo_fd = -1;
	termios_p = malloc(sizeof(struct termios));
	if (termios_p == NULL)
		return (printf("Error at malloc termios_p\n"));
	while (i < argc)
	{
		custo_fd = open(argv[i], O_RDONLY);
		if (custo_fd == -1)
			return (printf("Error at opening file %s\n", argv[i]));
		res = tcgetattr(custo_fd, termios_p);
		printf("fd[%d] = %s\ttcgetattr= %d\ttermios_p = %p\n", i, argv[i], res, termios_p);
		close(custo_fd);
		res = -1;
		i++;
		printf("%s\n", SEP_P);
	}
	return (1);
}
