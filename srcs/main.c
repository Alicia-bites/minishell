/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/09 11:08:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	g_msl_exit;
t_global       global;

int	main(int argc, char **argv, char **envp)
{
	t_minishell	msl;
	int		err;

	g_msl_exit = 0;
	err = 0;
//	if (ft_set_sigaction() == -1)
//		return (ft_panic_value(-1, __FILE__, ERR_SIGACTION,
//				EXIT_FAILURE));
	if (sig_program_set_action() == -1)
		return (ft_panic_value(-1, __FILE__, ERR_SIGACTION,
				EXIT_FAILURE));
	msl.env_lst = ft_lst_init();
	if (!msl.env_lst)
		return (EXIT_FAILURE);
	if (env_lst_set(envp, msl.env_lst))
	{
		ft_lst_free(msl.env_lst, &env_free);
		return (EXIT_FAILURE);
	}
	// env_lst_show(msl.env_lst);
//	test_antho(msl.env_lst);
// 	env_lst_show(msl.env_lst);
	get_input(&err, msl.env_lst);
	ft_lst_free(msl.env_lst, &env_free);
	return (0);
}
