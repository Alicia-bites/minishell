/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/18 17:46:55 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	g_exit;

static int	clean_up_env_list(t_ulist	**env_lst)
{
	ft_lst_free(env_lst, &env_free);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_ulist	**env_lst;
	int		err;

	(void)argc;
	(void)argv;
	g_exit = 0;
	err = 0;
	if (sig_program_set_action() == -1)
		return (ft_panic_value(-1, __func__, ERR_SIGACTION,
				EXIT_FAILURE));
	env_lst = ft_lst_init();
	if (!env_lst)
		return (EXIT_FAILURE);
	if (env_lst_set(envp, env_lst))
		return (clean_up_env_list(env_lst));
	if (env_lst_set_env_i(env_lst))
		return (clean_up_env_list(env_lst));
	get_input(&err, env_lst);
	ft_lst_free(env_lst, &env_free);
	return (0);
}
