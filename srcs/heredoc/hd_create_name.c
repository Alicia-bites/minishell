/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_create_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:54:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/17 15:58:55 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* @BRIEF:
 * create a string according to a specific input sequence:
 * tmp_directory + / +program_name + _ + index number
 * /tmp/smbash_1
 *
 * @PARAM:
 * t_list *tok: token node
 *
 * @RETURN:
 * <> NULL: address of the newly created string
 * NULL: error
 */
char	*hd_create_name(t_list *tok)
{
	char	*index;
	size_t	len_index;
	size_t	len_smb;
	size_t	len_tmp;
	char	*str;

	index = ft_itoa(tok->index);
	if (!index)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	hd_create_name_len(index, &len_index, &len_smb, &len_tmp);
	str = (char *)malloc(sizeof(char) + (len_tmp + 1 + len_smb + 1
				+ len_index + 1));
	if (!str)
	{
		free(index);
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	}
	str = ft_memmove(str, HD_TMP_DIR, len_tmp);
	ft_memmove(str + len_tmp, DIR_SEP, 1);
	ft_memmove(str + len_tmp + 1, SMB_NAME, len_smb);
	ft_memmove(str + len_tmp + 1 + len_smb, "_", 1);
	ft_memmove(str + len_tmp + 1 + len_smb + 1, index, len_index);
	str[len_tmp + 1 + len_smb + 1 + len_index] = '\0';
	free(index);
	return (str);
}
