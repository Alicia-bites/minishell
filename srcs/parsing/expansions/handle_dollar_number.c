/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:56:14 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/12 14:34:45 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_dollar_number(char *str, t_expanded **expanded_list,
	int *index, int i)
{
	if (str[i + 1] == '0' || same_with_brackets_zero(str, i))
		*expanded_list = create_dollar_list("smbash", (*index)++);
	else if (ft_isdigit(str[i + 1]) || same_with_brackets_number(str, i))
		*expanded_list = create_dollar_list("", (*index)++);
}
