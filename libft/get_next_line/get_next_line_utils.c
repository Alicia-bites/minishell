/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:34:51 by antho             #+#    #+#             */
/*   Updated: 2022/02/03 10:05:12 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

void	gnl_strncpy(char *s1, char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s2[i] && n > 0)
	{
		s1[i] = s2[i];
		i++;
		n--;
	}
	s1[i] = '\0';
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	lens1 = gnl_strlen(s1);
	lens2 = gnl_strlen(s2);
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
	{
		free(s1);
		return (0);
	}
	gnl_strncpy(str, s1, lens1);
	gnl_strncpy(&str[lens1], s2, lens2);
	str[lens1 + lens2] = '\0';
	free(s1);
	s1 = 0;
	return (&str[0]);
}
