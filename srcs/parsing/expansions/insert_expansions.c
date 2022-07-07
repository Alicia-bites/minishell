/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_expansions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:49:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/07 15:15:34 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static char	*malloc_newstr(int full_size,  t_expanded **expanded_list)
{
	char	*new_str;
		
	new_str = malloc(sizeof(char) * full_size + 1);
	if (!new_str)
	{
		ft_lstclear_dollar(expanded_list);
		ft_panic(MALLOC_FAILURE, 0);
		return (NULL);
	}
	ft_bzero(new_str, sizeof(char) * (full_size + 1));
	return (new_str);
}

static void	travel_to_next_str(int *k, char *str)
{
	while (ft_isalnum(str[*k]) || str[*k] == '{' || str[*k] == '}')
	{
		if (str[*k - 1] == '}' && ft_isalnum(str[*k]))
			break;
		(*k)++;
	}
}

char	*insert_expansions(int full_size, t_expanded *expanded_list, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*new_str;

	new_str = malloc_newstr(full_size, &expanded_list);
	i = 0;
	j = 0;
	k = 0;
	full_size -= count_double(str);
	while (i <= full_size)
	{
		if (k < ft_strlen(str) -1)
		{
			if (str[k] == '$' && str[k + 1] != '"')
			{
				j = 0;
				while (j < ft_strlen(expanded_list->expanded))
					new_str[i++] = expanded_list->expanded[j++];
				expanded_list = expanded_list->next;
				k++;
				travel_to_next_str(&k, str);
			}
		}
		if (str[k] != '$' && str[k] != '"')
			new_str[i++] = str[k++];
		else if (str[k] == '$' && str[k + 1] == '"' || str[k] == '"')
			k++;
	}
	new_str[i] = '\0';
	return (new_str);
}
