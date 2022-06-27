/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 17:45:46 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parse(char *str, t_list **token_list)
{	
	t_chartype	*input_list;
	int			i;
	int			length;

	i = 0;
	length = 0;
	if (ft_strstr(str, "$") && (!count_single(str) || count_single(str) % 2))
		str = expand_dollar(str, input_list);
	// printf("str = %s\n", str);
	length = ft_strlen(str);
	input_list = malloc(sizeof(t_chartype) * (length + 1));
	if (!input_list)
	{
		ft_panic(MALLOC_FAILURE, 0);
		return ;		
	}
	ft_bzero(input_list, sizeof(t_chartype) * (length + 1));
	count_quotes(str, input_list);
	while (i < length)
	{
		input_list[i].character = str[i];
		input_list[i].length = length;
		i++;
	}
	tokenize(input_list, token_list);
	print_lst(*token_list);
}
