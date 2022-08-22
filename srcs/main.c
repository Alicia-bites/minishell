/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/08/22 16:23:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	g_exit;

static int	set_interactive_display()
{
	struct termios	term;

	if (is_interactive())
	{
		if (tcgetattr(0, &term) == -1)
			return (-1);
		term.c_lflag &= ~ECHOCTL;
		if (tcsetattr(0, 0, &term) == -1)
			return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_ulist	**env_lst;
	int		err;

	(void)argc;
	(void)argv;
	g_exit = 0;
	err = 0;
	if (sig_program_set_action() == -1
		|| set_interactive_display() == -1)
	{
		rl_clear_history();
		return (ft_panic_value(-1, __func__, ERR_SIGACTION,
				EXIT_FAILURE));		
	}
	env_lst = ft_lst_init();
	if (!env_lst)
		return (EXIT_FAILURE);
	if (init_env_lst(envp, env_lst))
		return (EXIT_FAILURE);
	get_input(&err, env_lst);
	ft_lst_free(env_lst, &env_free);
	return (0);
}
