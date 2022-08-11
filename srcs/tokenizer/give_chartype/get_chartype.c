/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chartype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:01 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:45:02 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//FOR_DEBUG
// static void	print_chartype(t_chartype *input_list)
// {
// 	int	i;

// 	i = 0;
// 	while (input_list[i].character)
// 	{
// 		printf("%c -> %d\n", input_list[i].character, input_list[i].type);
// 		i++;		
// 	}	
// }

static int	is_expanded_op(int i)
{
	int				j;
	extern t_global	g_msl;

	j = 0;
	if (g_msl.saved_pos)
	{
		while (g_msl.saved_pos[j])
		{
			if (i == g_msl.saved_pos[j])
				return (1);
			j++;
		}
	}
	return (0);
}

// void	check_l_redir(int i, t_chartype **input_list)
// {
// 	if (i > 0)
// 	{
// 		if ((*input_list)[(i) - 1].character == '=')
// 			(*input_list)[i].type = CH_WORD;
// 		else
// 			(*input_list)[i].type = CH_L_REDIR;
// 	}
// 	else
// 		(*input_list)[i].type = CH_L_REDIR;
// }

// void	check_r_redir(int i, t_chartype **input_list)
// {
// 	if (i > 0)
// 	{
// 		if ((*input_list)[(i) - 1].character == '=')
// 			(*input_list)[i].type = CH_WORD;
// 		else
// 			(*input_list)[i].type = CH_R_REDIR;
// 	}
// 	else
// 		(*input_list)[i].type = CH_R_REDIR;
// }

void	get_chartype_second(int i, t_chartype **input_list)
{
	if ((*input_list)[i].character == '"' && (*input_list)->n_double == 1)
		(*input_list)[i].type = CH_WORD;
	else if ((*input_list)[i].character == '"' && (*input_list)->n_double > 1)
		(*input_list)[i].type = CH_D_QUOTE;
	else if ((*input_list)[i].character == '<')
		(*input_list)[i].type = CH_L_REDIR;
	else if ((*input_list)[i].character == '>')
		(*input_list)[i].type = CH_R_REDIR;
	else if ((*input_list)[i].character == '\n')
		(*input_list)[i].type = CH_BN;
}

int	get_chartype(t_chartype **input_list)
{
	int	i;

	i = 0;
	while ((*input_list)[i].character)
	{
		if (is_char_word((*input_list)[i].character) || is_expanded_op(i))
			(*input_list)[i].type = CH_WORD;
		else if (ft_isspace((*input_list)[i].character))
			(*input_list)[i].type = CH_SPACE;
		else if ((*input_list)[i].character == '|')
			(*input_list)[i].type = CH_PIPE;
		else if ((*input_list)[i].character == '\''
			&& (*input_list)->n_single == 1)
			(*input_list)[i].type = CH_WORD;
		else if ((*input_list)[i].character == '\''
			&& (*input_list)->n_single > 1)
			(*input_list)[i].type = CH_S_QUOTE;
		else
			get_chartype_second(i, input_list);
		i++;
	}
	return (i);
}
