/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/27 17:46:00 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	int		err;
	t_ulist	**env_lst;

	err = 0;
	if (ft_set_sigaction() == -1)
		printf("Setting up sigaction failed.\n");
	env_lst = ft_lst_init();
	if (!env_lst)
		return (EXIT_FAILURE);
	if (env_lst_set(envp, env_lst))
	{
		ft_lst_free(env_lst, &env_free);
		return (EXIT_FAILURE);
	}
	// env_lst_show(env_lst);
//	test_antho(env_lst);
// 	env_lst_show(env_lst);
	get_input(&err, env_lst);
	ft_lst_free(env_lst, &env_free);
	return (0);
}
