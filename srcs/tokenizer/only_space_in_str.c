/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_space_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:44:38 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/05 15:47:01 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// return 0 if str is only made of space(s)
int	only_space_in_str(char *str)
{
	int	not_space;
	int	i;
	
	not_space = 0;
	i = 0;
	while (str[i])
	{
		if (!is_char_space(str[i]))
			not_space++;
		i++;
	}
	return (not_space);
}