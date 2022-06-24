/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/24 14:56:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	handle_dollar_number(char *str, t_expanded **expanded_list,
	int *index, int i)
{
	if (str[i + 1] == '0')
		*expanded_list = create_dollar_list("minishell", *index++);
	else if (ft_isdigit(str[i + 1]))
		*expanded_list = create_dollar_list("", *index++);
}

static void	handle_dollar_name(int i, char *str, int *varsize,
	t_expanded **expanded_list, int *index)
{
	int	j;
	char *var;
	char *expanded;
	
	i++;
	j = i;
	while (is_varname(str[j]))
		j++;
	var = malloc_varname(str, i, j);
	*varsize = ft_strlen(var) + 1;
	expanded = getenv(var);		
	*expanded_list = create_dollar_list(expanded, *index++);
}

static void	handle_dollar_brackets(int i, char *str, int *varsize,
	t_expanded **expanded_list, int *index)
{
	int	j;
	char *var;
	char *expanded;
	
	i += 2;
	j = i;
	while (str[j] && str[j] != '}')
		j++;
	var = malloc_varname(str, i, j);
	*varsize = ft_strlen(var) + 2;
	expanded = getenv(var);		
	if (str[j] == '\0')
		expanded = 0;
	*expanded_list = create_dollar_list(expanded, *index++);
}

void	get_expanded(char *str, t_expanded **expanded_list, int i, int *varsize)
{
	extern	t_global	*g_global;
	static int			index = 0;

	if (g_global->expansions_list_cleared)
	{
		index = 0;
		g_global->expansions_list_cleared = 0;
	}
	if (ft_isdigit(str[i + 1]))
		handle_dollar_number(str, expanded_list, &index, i);
	else if (is_varname(str[i + 1]))
		handle_dollar_name(i, str, varsize, expanded_list, &index);
	else if (str[i + 1] == '{')
		handle_dollar_brackets(i, str, varsize, expanded_list, &index);
}
