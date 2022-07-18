/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:20:34 by abarrier          #+#    #+#             */
/*   Updated: 2022/07/15 09:54:25 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define SEP_P "####################"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	int	i;
	char	*res;
	int	custo_fd;

	if (argc == 1)
		return (0);
	i = 1;
	res = NULL;
	while (i < argc)
	{
		custo_fd = open(argv[i], O_RDONLY);
		if (custo_fd == -1)
			return (printf("Error at opening file %s\n", argv[i]));
		res = ttyname(custo_fd);
		printf("fd[%d] = %s\tttyname = %s\n", i, argv[i], res);
		close(custo_fd);
		free(res);
		res = NULL;
		i++;
		printf("%s\n", SEP_P);
	}
	return (1);
}
