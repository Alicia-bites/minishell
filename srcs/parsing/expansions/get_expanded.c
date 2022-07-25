/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_expanded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:48:34 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/25 17:25:01 by amarchan         ###   ########.fr       */
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

char	*ft_getenv(char *var, t_ulist *envp)
{
	t_env	*env;

	env = NULL;
	while (envp)
	{
		env = (t_env *)envp->content;
		if (!ft_strcmp(env->key, var))
		{
			if (!env->value)
				return (NULL);
			return (env->value);
		}
		envp = envp->next;
	}
	return (NULL);
}

static int	handle_dollar_name(t_exp_arg exp_arg, int i,
	t_expanded **expanded_list, int *index)
{
	int			j;
	char		*var;
	char		*expanded;
	t_position	position;
	int			varsize;

	i++;
	j = i;
	while (is_varname(exp_arg.str[j]))
		j++;
	var = malloc_varname(exp_arg.str, i, j);
	varsize = ft_strlen(var) + 1;
	expanded = ft_getenv(var, exp_arg.envp);
	position.move_cursor = ft_strlen(expanded) - (ft_strlen(var) + 1);
	position.pos = i - 1;
	if (found_operator(expanded))
		save_operator_position(expanded, position);
	if (!expanded || (i >= 2 && exp_arg.str[i - 2] == '<'))
		expanded = "";
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}

static int	handle_dollar_brackets(t_exp_arg exp_arg, int i, t_expanded **expanded_list,
	int *index)
{
	int		j;
	char	*var;
	char	*expanded;
	int		varsize;

	i += 2;
	j = i;
	while (exp_arg.str[j] && exp_arg.str[j] != '}')
		j++;
	var = malloc_varname(exp_arg.str, i, j);
	varsize = ft_strlen(var) + 2;
	expanded = getenv(var);
	if (exp_arg.str[j] == '\0' || (i >= 3 && exp_arg.str[i - 3] == '<'))
		expanded = 0;
	*expanded_list = create_dollar_list(expanded, (*index)++);
	free(var);
	return (varsize);
}

void	get_expanded(t_exp_arg exp_arg, t_expanded **expanded_list, int i, int *varsize)
{
	static int	index = 0;

	if (!*expanded_list)
		index = 0;
	if (ft_isdigit(exp_arg.str[i + 1]))
		handle_dollar_number(exp_arg.str, expanded_list, &index, i);
	else if (is_varname(exp_arg.str[i + 1]))
		*varsize = handle_dollar_name(exp_arg, i, expanded_list, &index);
	else if (exp_arg.str[i + 1] == '{')
		*varsize = handle_dollar_brackets(exp_arg, i, expanded_list, &index);
}
