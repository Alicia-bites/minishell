/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/23 20:08:29 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_varname(char c)
{
	if (ft_isalnum(c) || c == '_')
			return (1);
	return (0);
}

static void	handle_dollar_number(char *str, t_expanded **expanded_list,
	int *index, int i)
{
	if (str[i + 1] == '0')
		*expanded_list = create_dollar_list("minishell", *index++);
	else if (ft_isdigit(str[i + 1]))
		*expanded_list = create_dollar_list("", *index++);
}

void	get_expanded(char *str, t_expanded **expanded_list, int i, int *varsize)
{
	extern	t_global	*g_global;
	static int			index = 0;
	int					j;
	char 				*var;
	char				*expanded;

	if (g_global->expansions_list_cleared)
	{
		index = 0;
		g_global->expansions_list_cleared = 0;
	}
	if (ft_isdigit(str[i + 1]))
		handle_dollar_number(str, expanded_list, &index, i);
	else if (is_varname(str[i + 1]))
	{
		i++;
		j = i;
		while (is_varname(str[j]))
			j++;
		var = malloc_varname(str, i, j);
		*varsize = ft_strlen(var) + 1;
		expanded = getenv(var);
		if (!expanded)
		{
			printf("unknown variable\n");
			return ;			
		}
		*expanded_list = create_dollar_list(expanded, index++);
	}
}
