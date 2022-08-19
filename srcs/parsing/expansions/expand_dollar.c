/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:47:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 16:42:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	just_dollar_between_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (i >= 1 && str[i - 1] == '\''
				&& i + 1 < ft_strlen(str) && str[i + 1] == '\'')
				return (1);
			if (i >= 1 && str[i - 1] == '\"'
				&& i + 1 < ft_strlen(str) && str[i + 1] == '\"')
				return (1);
		}
		i++;
	}
	return (0);
}

static char	*handle_dollar_removing(t_exp_arg *exp_arg, int *malloc)
{
	exp_arg->str = remove_dollars(exp_arg->str);
	if (!exp_arg->str)
		return (ft_panic_null(-1, __func__, ERR_MALLOC));
	(*malloc)++;
	return (exp_arg->str);
}

char	*expand_dollar(t_exp_arg exp_arg, t_tab *tab)
{
	int					malloc;
	char				*new_str;
	int					full_size;
	t_expanded			*expanded_list;

	full_size = 0;
	expanded_list = NULL;
	malloc = 0;
	find_expansions(exp_arg, &expanded_list, &full_size);
	if ((ft_strstr(exp_arg.str, "$\'") || ft_strstr(exp_arg.str, "$\""))
		&& !just_dollar_between_quotes(exp_arg.str))
		if (!handle_dollar_removing(&exp_arg, &malloc))
			return (NULL);
	if (!expanded_list)
		return (exp_arg.str);
	full_size += get_full_size(expanded_list) + ft_strlen(exp_arg.str);
	new_str = insert_expansions(full_size, expanded_list, exp_arg.str);
	tab->tab_op = save_operator_index(exp_arg.str, new_str, expanded_list);
	tab->tab_quote = save_quote_index(exp_arg.str, new_str, expanded_list);
	ft_lstclear_dollar(&expanded_list);
	if (malloc)
		free(exp_arg.str);
	return (new_str);
}
