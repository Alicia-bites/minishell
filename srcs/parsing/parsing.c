/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:49:49 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/21 14:44:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	handle_dollar(char *str, t_chartype *input_list)
// {
// 	char	*loc;
// 	int		i;

// 	i = 0;
// 	loc = ft_strstr(str,"$");
// 	if (loc)
// 	{
// 		str = loc;
// 		printf("str[i] = %c\n", str[i]);
// 		if (str[i - 1] == '\'' && str[i + 1] == '\'')
// 			built_token(input_list, i - 1, i + 1);
// 	}
// }

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
	// handle_dollar(str, input_list);
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
