/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:04 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/29 15:00:28 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_token(t_chartype *input_list, t_list **token_list)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (start < (input_list[start].length - 1))
	{
		is_word(input_list, &start, &end, token_list);
		is_space(input_list, &start, &end, token_list);
		is_pipe(input_list, &start, &end, token_list);
		is_s_quote(input_list, &start, &end, token_list);
		is_d_quote(input_list, &start, &end, token_list);
		is_l_redir(input_list, &start, &end, token_list);
		is_r_redir(input_list, &start, &end, token_list);
		is_dl_redir(input_list, &start, &end, token_list);
		is_dr_redir(input_list, &start, &end, token_list);
		is_bn(input_list, &start, &end, token_list);
		// *token_list = is_intpoint(input_list, &start, &end);
	}
}
