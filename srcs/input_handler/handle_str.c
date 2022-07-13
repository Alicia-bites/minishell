/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:24:51 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/13 16:25:04 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_str(char **str, t_list **token_list, int *err)
{
		ft_parse(*str, token_list, err);
		print_lst(*token_list);
		// execute_command(token_list);
		ft_lstclear(token_list);
		if (is_not_empty(*str))
			add_history(*str);
}