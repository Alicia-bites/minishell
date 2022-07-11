/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:57:54 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/29 14:59:37 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_to_list(char *token, t_list **token_list)
{
	static int	i = 0;
	
	if (!*token_list)
		i = 0;
	*token_list = create_list(token, i++, 0);
}