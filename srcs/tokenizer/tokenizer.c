/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/29 15:02:11 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tokenize(t_chartype *input_list, t_list **token_list)
{
	
	get_chartype(&input_list);
	get_token(input_list, token_list);
	// print_lst(*token_list);
	get_toktype(input_list, token_list);
}
