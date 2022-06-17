/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/17 09:31:59 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// Parse arguments and return inputs_list(s)
char	*ft_parse(char *str)
{	
	char	**inputs_list;
	// int		i;
	
	// i = 0;
	inputs_list = ft_split(str, 32);
	//FOR DEBUG
	// while (inputs_list[i])
	// 	printf("%s\n", inputs_list[i++]);
	// puts("-------------------------------------------------------------");
	//END
	sort_inputs(inputs_list);
	return (0);
}
