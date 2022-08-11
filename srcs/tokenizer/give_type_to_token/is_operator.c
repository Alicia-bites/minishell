/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:50 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:44:43 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_toktype	is_operator(char *str)
{
	extern t_global	g_msl;

	if (str)
	{
		if (ft_strstr(str, "|"))
		{
			g_msl.seen_tok_cmd = 0;
			return (TOK_PIPE);
		}
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
