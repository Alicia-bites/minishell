/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:10:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 12:21:54 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*hd_write_expansion(char *str, t_ulist **envp)
{
	char		*output;
	t_exp_arg	exp_arg;

	output = NULL;
	exp_arg.envp = *envp;
	exp_arg.str = str;
	if (ft_strstr(str, "$"))
	{
		output = expand_dollar_heredoc(exp_arg);
		free(str);
	}
	else
		output = str;
	return (output);
}
