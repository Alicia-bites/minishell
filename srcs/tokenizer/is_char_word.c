/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:58:19 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 18:52:38 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_char_word(char c)
{
	if (ft_isalnum(c) || c == ';' || c == ',' || c == ':' || c == '.'
		|| c == '_' || c == '-' || c == '!' || c == '=' || c == '~'
		|| c == '#' || c == '+' || c == '-' || c == '*' || c == '&'
		|| c == '`' || c == '^' || c == '|' || c == '\\' || c == '/'
		|| c == '@' || c == '_' || c == ')' || c == '(' || c == '%'
		|| c == '$'|| c == '?' || c == '}')
		//|| c == '€' || (long long unsigned) c == '£' || c == '¬')
			return (1);
	return (0);
}