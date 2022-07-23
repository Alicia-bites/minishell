/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_filename.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 09:47:37 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/22 11:48:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Is filename a token that is placed after a <, > or >>
// or after a <, > or >> and then a space
int	is_filename(t_list **token_list)
{
	if (redir_token(token_list))
		return (1);
	if (redir_space_token(token_list))
		return (1);
	return (0);
}
