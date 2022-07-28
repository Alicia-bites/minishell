/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 12:07:44 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/28 14:51:54 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize(t_chartype *input_list, t_list **token_list)
{
	get_chartype(&input_list);
	get_token(input_list, token_list);
	// print_lst(*token_list);
	delete_spaces(token_list);
	get_toktype(token_list);
	concatenate_export_args(token_list);
}
