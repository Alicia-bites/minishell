/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_expansions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:49:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/24 14:33:56 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*insert_expansions(int full_size, t_expanded *expanded_list, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*new_str;

	new_str = malloc(sizeof(char) * full_size + 1);
	if (!new_str)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	ft_bzero(new_str, sizeof(char) * (full_size + 1));
	i = 0;
	j = 0;
	k = 0;
	while (i <= full_size)
	{
		if (str[k] == '$')
		{
			j = 0;
			while (j < ft_strlen(expanded_list->expanded))
				new_str[i++] = expanded_list->expanded[j++];
			expanded_list = expanded_list->next;
			k++;
			while (ft_isalnum(str[k]) || str[k] == '{' || str[k] == '}')
				k++;				
		}
		new_str[i++] = str[k++];
	}
	new_str[i] = '\0';
	return (new_str);
}
