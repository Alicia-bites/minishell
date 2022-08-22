/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:34:20 by antho             #+#    #+#             */
/*   Updated: 2022/02/03 09:57:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gnl_shiftbuf(char *buf)
{
	char	*nl;
	size_t	inl;

	nl = gnl_strchr(buf, '\n');
	inl = 0;
	if (nl == 0)
		buf[0] = '\0';
	else
	{
		inl = gnl_strlen(buf);
		gnl_strncpy(buf, &buf[inl], (size_t)BUFFER_SIZE);
	}
}

static void	gnl_eof(char *buf, char *line)
{
	if (!line || line[0] == '\0')
	{
		if (line)
			free(line);
		free(buf);
	}
}

static char	*gnl_line(int fd, char *buf)
{
	char	*line;
	ssize_t	letters;

	line = 0;
	letters = 0;
	line = gnl_strjoin(line, buf);
	while (!gnl_strchr(buf, '\n'))
	{
		letters = read(fd, buf, (size_t)BUFFER_SIZE);
		if (letters <= 0)
			break ;
		buf[letters] = '\0';
		line = gnl_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (0);
	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * (size_t)(BUFFER_SIZE + 1));
		if (!buf)
			return (0);
		buf[0] = '\0';
	}
	line = gnl_line(fd, buf);
	if (!line || line[0] == '\0')
	{
		gnl_eof(buf, line);
		buf = 0;
		line = 0;
	}
	else
		gnl_shiftbuf(buf);
	return (line);
}
