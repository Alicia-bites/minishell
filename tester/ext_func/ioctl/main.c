/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/15 10:13:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stropts.h>

#define SEP_P "####################"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	int	i;
	int	res;
	int	custo_fd;
	int	request;

	if (argc == 1)
		return (0);
	i = 1;
	res = -1;
	request = 0;
	while (i < argc)
	{
		custo_fd = open(argv[i], O_RDONLY);
		if (custo_fd == -1)
			return (printf("Error at opening file %s\n", argv[i]));
		res = ioctl(custo_fd, request);
		printf("fd[%d] = %s\trequest = %d\tioctl = %d\n", i, argv[i], request, res);
		close(custo_fd);
		res = -1;
		request= 0;
		i++;
		printf("%s\n", SEP_P);
	}
	return (1);
}
