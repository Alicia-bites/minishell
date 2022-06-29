/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chartype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/29 15:02:00 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_chartype(t_chartype *input_list)
{
	int	i;
	
	i = 0;
	while (input_list[i].character)
	{
		printf("%c -> %d\n", input_list[i].character, input_list[i].type);
		i++;		
	}	
}

int	get_chartype(t_chartype **input_list)
{
	int	i;

	i = 0;
	while ((*input_list)[i].character)
	{
		if (is_char_word((*input_list)[i].character))
			(*input_list)[i].type = CH_WORD;
		if (ft_isspace((*input_list)[i].character))
			(*input_list)[i].type = CH_SPACE;
		if ((*input_list)[i].character == '|')
			(*input_list)[i].type = CH_PIPE;
		if ((*input_list)[i].character == '\'' && (*input_list)->n_single == 1)
			(*input_list)[i].type = CH_WORD;
		else if ((*input_list)[i].character == '\'' && (*input_list)->n_single > 1)
			(*input_list)[i].type = CH_S_QUOTE;
		if ((*input_list)[i].character == '"' && (*input_list)->n_double == 1)
			(*input_list)[i].type = CH_WORD;
		else if ((*input_list)[i].character == '"' && (*input_list)->n_double > 1)
			(*input_list)[i].type = CH_D_QUOTE;
		if ((*input_list)[i].character == '<')
			(*input_list)[i].type = CH_L_REDIR;
		if ((*input_list)[i].character == '>')
			(*input_list)[i].type = CH_R_REDIR;
		if ((*input_list)[i].character == '\n')
			(*input_list)[i].type = CH_BN;
		
		i++;
	}
	// print_chartype(*input_list);
	return (i);
}