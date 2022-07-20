/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/20 14:48:12 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int	err;

	err = 0;
 	t_ulist	**env_lst;

	if (ft_set_sigaction() == -1)
		printf("Setting up sigaction failed.\n");
 	env_lst = ft_lst_init();
 	if (!env_lst)
 		return (1);
 	if (env_lst_set(envp, env_lst))
 	{
 		ft_lst_free(env_lst, &env_free);
 		return (2);
 	}
// 	env_lst_show(env_lst);
//	test_antho(env_lst);
// 	env_lst_show(env_lst);
	get_input(&err, env_lst);
 	ft_lst_free(env_lst, &env_free);
	return (0);
}
