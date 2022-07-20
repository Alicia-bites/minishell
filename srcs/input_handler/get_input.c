/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:25:39 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/19 18:59:24 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_input(int *err, t_ulist **envp)
{
	char	*str;
	t_list	*token_list;
	
	token_list = NULL;
	str = NULL;
	while (42)
	{
		read_line(&str);
		if (!str)
			exit_minishell(&token_list, err, envp);
		if (str[0] != 0)
			handle_str(&str, &token_list, err, envp);
	}
	return (*err);
}
