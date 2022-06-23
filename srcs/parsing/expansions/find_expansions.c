/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_expansions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 19:50:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	find_expansions(char *str, t_expanded **expanded_list, int *full_size)
{
	int			i;
	int			varsize;
	
	varsize = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			get_expanded(str, expanded_list, i, &varsize);
			*full_size -= varsize;
		}
		i++;
	}
}