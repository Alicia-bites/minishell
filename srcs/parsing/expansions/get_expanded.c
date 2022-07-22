/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 19:16:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_dollar_number(char *str, t_expanded **expanded_list,
	int *index, int i)
{
	if (str[i + 1] == '0')
		*expanded_list = create_dollar_list("minishell", (*index)++);
	else if (ft_isdigit(str[i + 1]))
		*expanded_list = create_dollar_list("", (*index)++);
}

static int	handle_dollar_name(char *str, int i,
	t_expanded **expanded_list, int *index)
{
	int			j;
	char		*var;
	char		*expanded;
	t_position	position;
	int			varsize;

	i++;
	j = i;
	while (is_varname(str[j]))
		j++;
	var = malloc_varname(str, i, j);
	varsize = ft_strlen(var) + 1;
	expanded = getenv(var);
	position.move_cursor = ft_strlen(expanded) - (ft_strlen(var) + 1);
	position.pos = i - 1;
	if (found_operator(expanded))
		save_operator_position(expanded, position);
	if (!expanded || (i >= 2 && str[i - 2] == '<'))
		expanded = "";
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}

static int	handle_dollar_brackets(char *str, int i, t_expanded **expanded_list,
	int *index)
{
	int		j;
	char	*var;
	char	*expanded;
	int		varsize;

	i += 2;
	j = i;
	while (str[j] && str[j] != '}')
		j++;
	var = malloc_varname(str, i, j);
	varsize = ft_strlen(var) + 2;
	expanded = getenv(var);
	if (str[j] == '\0' || (i >= 3 && str[i - 3] == '<'))
		expanded = 0;
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}

void	get_expanded(char *str, t_expanded **expanded_list, int i, int *varsize)
{
	static int	index = 0;
	
	if (!*expanded_list)
		index = 0;
	if (ft_isdigit(str[i + 1]))
		handle_dollar_number(str, expanded_list, &index, i);
	else if (is_varname(str[i + 1]))
		*varsize = handle_dollar_name(str, i, expanded_list, &index);
	else if (str[i + 1] == '{')
		*varsize = handle_dollar_brackets(str, i, expanded_list, &index);
}
