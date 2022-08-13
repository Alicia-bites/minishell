/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_create_name_len.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 09:28:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 09:30:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hd_create_name_len(char *index, size_t *len_index, size_t *len_smb,
		size_t *len_tmp)
{
	*len_index = ft_strlen(index);
	*len_smb = ft_strlen(SMB_NAME);
	*len_tmp = ft_strlen(HD_TMP_DIR);
}
