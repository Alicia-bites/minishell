/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:01:15 by amarchan          #+#    #+#             */
/*   Updated: 2021/12/10 10:01:21 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (arr);
}

static int	ft_count_splits(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				i++;
			n++;
		}
	}
	return (n);
}

static char	*ft_copy(char *str, int n)
{
	int		i;
	char	*output;

	i = 0;
	output = malloc(sizeof(char) * (n + 1));
	if (!output)
		return (NULL);
	while (str[i] && i < n)
	{
		output[i] = str[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

static char	**ft_do_split(char **array, char *str, char sep, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (str[i] == sep && str[i])
			i++;
		str = str + i;
		i = 0;
		while (str[i] != sep && str[i])
			i++;
		array[j++] = ft_copy(str, i);
		if (!array[j - 1])
			return (ft_free(array));
		str = str + i;
		i = 0;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		splits;
	char	*copy;	

	if (!s)
		return (0);
	copy = (char *)s;
	splits = ft_count_splits(copy, c);
	array = malloc(sizeof(char *) * (splits + 1));
	if (!array)
		return (NULL);
	if (splits == 0)
		array[0] = NULL;
	else
		array = ft_do_split(array, copy, c, splits);
	return (array);
}
