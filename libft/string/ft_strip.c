/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:45:20 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/28 11:57:53 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//get rid of extra spaces before argument
void	ft_strip(char *s)
{
	ft_left_strip(s);
	ft_right_strip(s);
}
