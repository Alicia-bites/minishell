/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_write_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:10:45 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/15 10:11:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*hd_write_expansion(char *str, t_ulist **envp)
{
	char		*output;
	t_exp_arg	exp_arg;
	
	output = NULL;
	printf("output 0: ptr = %p\n", output);
	exp_arg.envp = *envp;
	exp_arg.str = str;
	if (ft_strstr(str, "$"))
	{
		printf("output 1-1: ptr = %p\n", output);
		output = expand_dollar_heredoc(exp_arg);
		//output = str;
		printf("output 1-2: ptr = %p\n", output);
		free(str);
	}
	else
	{
		output = str;
		printf("output 2: ptr = %p\n", output);
	}
	printf("output 3: ptr = %p\n", output);
	return (output);
}
