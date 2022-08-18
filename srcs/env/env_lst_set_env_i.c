/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_set_env_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 10:51:17 by abarrier          #+#    #+#             */
/*   Updated: 2022/08/18 17:48:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_lst_set_env_i(t_ulist **env_lst)
{
	char	*env_value;

	if (env_lst_set_env_i_init(env_lst))
		return (EXIT_FAILURE);
	if (env_lst_set_env_i_value(env_lst, ENV_PATH_NAME,
			ENV_PATH_DFT_VAL1))
		return (EXIT_FAILURE);
	env_value = do_pwd_getpath();
	if (!env_value)
		return (ft_panic_value(-1, __FILE__, ERR_MALLOC, EXIT_FAILURE));
	if (env_lst_set_env_i_value(env_lst, ENV_PWD_NAME, env_value))
	{
		free(env_value);
		return (EXIT_FAILURE);
	}
	free(env_value);
	return (0);
}
