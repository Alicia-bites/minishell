/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/06/30 15:56:39 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_input(void)
{
	char	*str;
	t_list	*token_list;
	
	token_list = NULL;
	str = NULL;
	while (42)
	{
		str = readline("$: ");
		if (!str)
			return (0);
		if (str[0] != 0)
		{
			ft_parse(str, &token_list);
			print_lst(token_list);
			// execute_command(token_list);
			ft_lstclear(&token_list);
			printf("token_list (main) = %p\n", token_list);
			if (is_not_clone(str) && is_not_empty(str))
				add_history(str);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_ulist	**env_lst;
	t_cmd	test_cmd;
//	char test_cmd_arg[] = "env";
//	char *test_cmd_fullcmd[] = { "env", NULL };
	char test_cmd_arg[] = "env ANTHO=toto";
	char *test_cmd_fullcmd[] = { "env", "ANTHO=toto", NULL };
//	char test_cmd_arg[] = "env ANTHO=toto echo $ANTHO";
//	char *test_cmd_fullcmd[] = { "env", "ANTHO=toto", "echo", "$ANTHO", NULL };
//	char test_cmd_arg[] = "env echo $ANTHO";
//	char *test_cmd_fullcmd[] = { "env", "echo", "$ANTHO", NULL };
	char test_cmd_path[] = "built-in";

	test_cmd.arg = test_cmd_arg;
	test_cmd.fullcmd = test_cmd_fullcmd;
	test_cmd.fullpath = test_cmd_path;

	env_lst = ft_lst_init();
	if (!env_lst)
		return (1);
	if (env_lst_set(envp, env_lst))
	{
		ft_lst_free(env_lst, &env_free);
		return (2);
	}
	//env_lst_show(env_lst);
	do_env(env_lst, &test_cmd);
	ft_lst_free(env_lst, &env_free);
	//get_input();
	return (0);
}
