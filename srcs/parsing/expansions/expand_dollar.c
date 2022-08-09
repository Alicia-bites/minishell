/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/09 13:52:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_my_dollars(char *str)
{
	int	i;
	int n;
	
	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (i + 1 < ft_strlen(str) && str[i] == '$'
			&& (str[i + 1] == '\'' || str[i + 1] == '"'))
			n++;
		i++;
	}
	return (n);
}

char *remove_dollars( char *str)
{
	int	i;
	int j;
	int	n;
	char *output;

	n = ft_strlen(str) - count_my_dollars(str);
	output = malloc(sizeof(char) * (n + 1));
	if (!output)
		return (ft_panic_null(MALLOC_FAILURE, __FILE__, NULL));
	i = 0;
	j = 0;
	while (i < n)
	{
		if (j + 1 < ft_strlen(str) && str[j] == '$'
			&& (str[j + 1] == '\'' || str[j + 1] == '"'))
				j++;
		output[i++] = str[j];
		j++;
	}
	output[i] = '\0';
	printf("%s\n", output);
	return (output);
}

char	*expand_dollar(t_exp_arg exp_arg)
{
	char				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	expanded_list = NULL;
	find_expansions(exp_arg, &expanded_list, &full_size);
	exp_arg.str = remove_dollars(exp_arg.str);
	if (!expanded_list)
	{
		return (exp_arg.str);
	}
	full_size += get_full_size(expanded_list) + ft_strlen(exp_arg.str);
	new_str = insert_expansions(full_size, expanded_list, exp_arg.str);
	ft_lstclear_dollar(&expanded_list);
	ft_lstclear_back_dollar(&expanded_list);
	return (new_str);
}
