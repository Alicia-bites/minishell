/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_trim_quotes_token.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:22:16 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/19 19:26:33 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_up_trim_quotes_token(char **str, int **tab, char *output)
{
	if (ft_strcmp(*str, output))
		free(*str);
	if (*tab)
		free(*tab);
}
