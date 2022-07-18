/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 15:48:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_toktype	is_operator(char *str)
{
	if (str)
	{
		if (ft_strstr(str, "|"))
			return (TOK_PIPE);
		if (ft_strstr(str, "<<"))
			return (TOK_DL_REDIR);
		if (ft_strstr(str, ">>"))
			return (TOK_DR_REDIR);
		if (ft_strstr(str, "<"))
			return (TOK_L_REDIR);
		if (ft_strstr(str, ">"))
			return (TOK_R_REDIR);
	}
	return (0);
}
