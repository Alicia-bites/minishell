/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/11 08:23:12 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	g_msl_exit;
t_global       global;

int	main(int argc, char **argv, char **envp)
{
	t_ulist	**env_lst;
	int		err;

	g_msl_exit = 0;
	err = 0;
	if (sig_program_set_action() == -1)
		return (ft_panic_value(-1, __FILE__, ERR_SIGACTION,
				EXIT_FAILURE));
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
