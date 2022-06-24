/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/24 12:18:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*expand_dollar(char *str, t_chartype *input_list)
{
	extern	t_global	*g_global;
	char 				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	find_expansions(str, &expanded_list, &full_size);
	full_size += get_full_size(expanded_list) + ft_strlen(str);
	new_str = insert_expansions(full_size, expanded_list, str);
	ft_lstclear_back(&expanded_list);
	g_global->expansions_list_cleared = 1;
	return (new_str);
}
