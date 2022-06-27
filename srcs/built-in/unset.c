/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:21:21 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/27 09:20:40 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * Test
 * export ANTHO=test
 * unset ANTHO ==> Ok, always return(0)
 * unset "ANTHO" ==> Ok, always return(0)
 * unset 'ANTHO' ==> Ok, always return(0)
 * unset $ANTHO
 */
int	do_unset(char *str)
{
	return (0);
}
