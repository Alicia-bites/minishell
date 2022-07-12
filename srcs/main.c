/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/12 11:06:20 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_global global;

int	get_input(t_ulist **env_list)
{
	char	*str;
	int		err;
	t_list	*token_list;
	t_ulist	**cmd_list;
	
	token_list = NULL;
	cmd_list = NULL;
	str = NULL;
	err = 0;
	while (42)
	{
		global.readline = 1;
		while (global.readline)
		{
			global.readline = 0;
			str = readline("$: ");
			break ;
		}
		if (!str)
		{
			rl_clear_history();
			ft_lstclear(&token_list);
			return (0);
		}
		if (str[0] != 0)
		{
			ft_parse(str, &token_list);
			print_lst(token_list);
			cmd_list = ft_lst_init();
			if (!cmd_list)
			{
				printf("ERRROR TO BE DEFINED, FREE TOKEN_LIST AND SO ON...\n");
			}
			cmd_create_lst(token_list, env_list, cmd_list);
			ft_lst_func_lst(cmd_list, &cmd_show);
			// execute_command(token_list);
			ft_lstclear(&token_list);
			//printf("token_list (main) = %p\n", token_list);
			if (is_not_empty(str))
				add_history(str);
			ft_lst_free(cmd_list, &cmd_free);
		}
		//free(str);
	}
	rl_clear_history();
	printf("err = %d\n", err);
	return (err);
}

int	main(int argc, char **argv, char **envp)
{
 	t_ulist	**env_lst;
// 	t_cmd	test_env_cmd;
// //	char test_env_cmd_arg[] = "env";
// //	char *test_env_cmd_fullcmd[] = { "env", NULL };
// 	char test_env_cmd_arg[] = "env ANTHO=toto";
// 	char *test_env_cmd_fullcmd[] = { "env", "ANTHO=toto", NULL };
// //	char test_env_cmd_arg[] = "env ANTHO=toto echo $ANTHO";
// //	char *test_env_cmd_fullcmd[] = { "env", "ANTHO=toto", "echo", "$ANTHO", NULL };
// //	char test_env_cmd_arg[] = "env echo $ANTHO";
// //	char *test_env_cmd_fullcmd[] = { "env", "echo", "$ANTHO", NULL };
// 	char test_env_cmd_path[] = "built-in";

// 	test_env_cmd.arg = test_env_cmd_arg;
// 	test_env_cmd.fullcmd = test_env_cmd_fullcmd;
// 	test_env_cmd.fullpath = test_env_cmd_path;

// 	t_cmd	test_unset_cmd;
// 	char test_unset_cmd_arg[] = "unset";
// 	char *test_unset_cmd_fullcmd[] = { "unset", NULL };
// //	char test_unset_cmd_arg[] = "unset PATH";
// //	char *test_unset_cmd_fullcmd[] = { "unset", "PATH", NULL };
// 	char test_unset_cmd_path[] = "built-in";

// 	test_unset_cmd.arg = test_unset_cmd_arg;
// 	test_unset_cmd.fullcmd = test_unset_cmd_fullcmd;
// 	test_unset_cmd.fullpath = test_unset_cmd_path;

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
 	//env_lst_show(env_lst);
// 	do_env(env_lst, &test_env_cmd);
// 	printf("%s\n", SEP_P);
// 	do_unset(env_lst, &test_unset_cmd);
	get_input(env_lst);
 	ft_lst_free(env_lst, &env_free);
	return (0);
}
