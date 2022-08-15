/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:55:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/15 09:24:35 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_dollar_name(t_exp_arg exp_arg, int i,
	t_expanded **expanded_list, int *index)
{
	int			j;
	char		*var;
	char		*expanded;
	int			varsize;

	i++;
	j = i;
	while (is_varname(exp_arg.str[j]))
		j++;
	var = malloc_varname(exp_arg.str, i, j);
	varsize = ft_strlen(var) + 1;
	expanded = ft_getenv(var, exp_arg.envp);
	if (!expanded || (i >= 2 && exp_arg.str[i - 2] == '<'))
		expanded = ft_strdup("");
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}
