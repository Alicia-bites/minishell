/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/21 12:00:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_dollar(char *str)
{
	char 				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	expanded_list = NULL;
	find_expansions(str, &expanded_list, &full_size);
	if (!full_size)
		return (str);
	full_size += get_full_size(expanded_list) + ft_strlen(str);
	new_str = insert_expansions(full_size, expanded_list, str);
	ft_lstclear_dollar(&expanded_list);
	ft_lstclear_back_dollar(&expanded_list);
	// check_if_operator(str, new_str);
	// printf("new_str = %s\n", new_str);
	// printf("new_str[19] = %c\n", new_str[19]);
	// printf("new_str[20] = %c\n", new_str[20]);
	return (new_str);
}
