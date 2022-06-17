/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:45:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/16 11:36:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//get rid of extra spaces before argument
void	ft_strip(char *s)
{
	ft_lstrip(s);
	ft_rstrip(s);
}
