/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_brackets.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:54:37 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:34:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_dollar_brackets(t_exp_arg exp_arg, int i,
	t_expanded **expanded_list, int *index)
{
	int			j;
	char		*var;
	char		*expanded;
	int			varsize;

	i += 2;
	j = i;
	while (exp_arg.str[j] && exp_arg.str[j] != '}')
		j++;
	var = malloc_varname(exp_arg.str, i, j);
	varsize = ft_strlen(var) + 2;
	expanded = ft_getenv(var, exp_arg.envp);
	if (exp_arg.str[j] == '\0' || (i >= 3 && exp_arg.str[i - 3] == '<'))
		expanded = "";
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}
