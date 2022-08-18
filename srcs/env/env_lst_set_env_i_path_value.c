/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set_env_i_path_value.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:57:56 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 19:52:45 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_lst_set_env_i_path_value(void)
{
	char	*str;
	size_t	len_p1;
	size_t	len_p2;
	size_t	len_p3;

	len_p1 = (size_t)ENV_PATH_DFT_LEN1;
	len_p2 = (size_t)ENV_PATH_DFT_LEN2;
	len_p3 = (size_t)ENV_PATH_DFT_LEN3;
	printf("ENV P1: %s\n", ENV_PATH_DFT_VAL1);
	printf("ENV P2: %s\n", ENV_PATH_DFT_VAL2);
	printf("ENV P3: %s\n", ENV_PATH_DFT_VAL3);
	str = (char *)malloc(sizeof(char) * (len_p1 + len_p2 + len_p3 + 1));
	if (!str)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	str = ft_memmove(str, ENV_PATH_DFT_VAL1, len_p1);
	ft_memmove(str + len_p1, ENV_PATH_DFT_VAL2, len_p2);
	ft_memmove(str + len_p1 + len_p3, ENV_PATH_DFT_VAL3, len_p3);
	str[len_p1 + len_p2 + len_p3] = '\0';
	return (str);
}
