/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hd_create_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <abarrier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:54:09 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/13 09:31:27 by abarrier         ###   ########.fr       */
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
 * t_cmd *cmd: cmd node
 *
 * @RETURN:
 * <> NULL: address of the newly created string
 * NULL: error
 */
char	*hd_create_name(t_list *tok, t_cmd *cmd)
{
	char	*index;
	size_t	len_index;
	size_t	len_smb;
	size_t	len_tmp;

	index = ft_itoa(tok->index);
	if (!index)
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	hd_create_name_reset(cmd);
	hd_create_name_len(index, &len_index, &len_smb, &len_tmp);
	cmd->hd_name = (char *)malloc(sizeof(char) + (len_tmp + 1 + len_smb + 1
				+ len_index + 1));
	if (!cmd->hd_name)
	{
		free(index);
		return (ft_panic_null(-1, __FILE__, ERR_MALLOC));
	}
	cmd->hd_name = ft_memmove(cmd->hd_name, HD_TMP_DIR, len_tmp);
	ft_memmove(cmd->hd_name + len_tmp, DIR_SEP, 1);
	ft_memmove(cmd->hd_name + len_tmp + 1, SMB_NAME, len_smb);
	ft_memmove(cmd->hd_name + len_tmp + 1 + len_smb, "_", 1);
	ft_memmove(cmd->hd_name + len_tmp + 1 + len_smb + 1, index, len_index);
	cmd->hd_name[len_tmp + 1 + len_smb + 1 + len_index] = '\0';
	free(index);
	return (cmd->hd_name);
}
