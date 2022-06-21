/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 13:56:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_parse(char *str)
{	
	t_chartype	*input_list;
	int			i;
	int			length;

	i = 0;
	length = ft_strlen(str);
	input_list = malloc(sizeof(t_chartype) * (length + 1));
	if (!input_list)
		return (NULL);
	ft_bzero(input_list, sizeof(t_chartype) * (length + 1));
	count_quotes(str, input_list);
	while (i < length)
	{
		input_list[i].character = str[i];
		input_list[i].length = length;
		i++;
	}
	//FOR DEBUG
	// while (i != -1)
	// {
	// 	printf("%c", input_list[i].character);
	// 	i--;
	// }
	//END
	puts("");
	tokenize(input_list);
	// sort_input(input_list);
	return (0);
}
