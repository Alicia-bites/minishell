/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/18 15:12:05 by abarrier         ###   ########.fr       */
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

static void	antho_test(t_ulist **env_lst)
{
 	t_cmd	test_env_cmd;
// //	char test_env_cmd_arg[] = "env";
// //	char *test_env_cmd_fullcmd[] = { "env", NULL };
// 	char test_env_cmd_arg[] = "env ANTHO=toto";
// 	char *test_env_cmd_fullcmd[] = { "env", "ANTHO=toto", NULL };
	char test_env_cmd_arg[] = "env ANTHO=toto echo $ANTHO";
	char *test_env_cmd_fullcmd[] = { "env", "ANTHO=toto", "echo", "$ANTHO", NULL };
// //	char test_env_cmd_arg[] = "env echo $ANTHO";
// //	char *test_env_cmd_fullcmd[] = { "env", "echo", "$ANTHO", NULL };
 	char test_env_cmd_path[] = "built-in";

 	test_env_cmd.arg = test_env_cmd_arg;
 	test_env_cmd.fullcmd = test_env_cmd_fullcmd;
 	test_env_cmd.fullpath = test_env_cmd_path;
 	do_env(env_lst, &test_env_cmd);
	ft_lst_func_lst(env_lst, &do_export_show);
	ft_lst_func_lst(env_lst, &do_env_show);
 	printf("%s\n", SEP_P);

 	t_cmd	test_export_cmd;
// 	char test_export_cmd_arg[] = "export";
// 	char *test_export_cmd_fullcmd[] = { "export", NULL };
	char test_export_cmd_arg[] = "export ANTHO ANTHO=toto=titi=tata ANTHO ALICIA=BG @ELON ANTHO=";
	char *test_export_cmd_fullcmd[] = { "export", "ANTHO", "ANTHO=toto=titi=tata", "ANTHO", "ALICIA=BG", "@ELON", "ANTHO=", NULL };
 	char test_export_cmd_path[] = "built-in";

 	test_export_cmd.arg = test_export_cmd_arg;
 	test_export_cmd.fullcmd = test_export_cmd_fullcmd;
 	test_export_cmd.fullpath = test_export_cmd_path;
	do_export(env_lst, &test_export_cmd);
	ft_lst_func_lst(env_lst, &do_export_show);
	ft_lst_func_lst(env_lst, &do_env_show);
 	printf("%s\n", SEP_P);

 	t_cmd	test_unset_cmd;
// 	char test_unset_cmd_arg[] = "unset";
// 	char *test_unset_cmd_fullcmd[] = { "unset", NULL };
	char test_unset_cmd_arg[] = "unset ANTHO";
	char *test_unset_cmd_fullcmd[] = { "unset", "ANTHO", NULL };
 	char test_unset_cmd_path[] = "built-in";

 	test_unset_cmd.arg = test_unset_cmd_arg;
 	test_unset_cmd.fullcmd = test_unset_cmd_fullcmd;
 	test_unset_cmd.fullpath = test_unset_cmd_path;
 	do_unset(env_lst, &test_unset_cmd);
 	ft_lst_func_lst(env_lst, &do_export_show);
	ft_lst_func_lst(env_lst, &do_env_show);
	printf("%s\n", SEP_P);

 	t_cmd	test_cd_cmd;
 	char test_cd_cmd_arg[] = "cd";
 	char *test_cd_cmd_fullcmd[] = { "cd", NULL };
 	char test_cd_cmd_path[] = "built-in";

	test_cd_cmd.arg = test_cd_cmd_arg;
 	test_cd_cmd.fullcmd = test_cd_cmd_fullcmd;
 	test_cd_cmd.fullpath = test_cd_cmd_path;
 	do_cd(env_lst, &test_cd_cmd);
 	ft_lst_func_lst(env_lst, &do_export_show);
	ft_lst_func_lst(env_lst, &do_env_show);
	printf("%s\n", SEP_P);

}

int	main(int argc, char **argv, char **envp)
{
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
 	env_lst_show(env_lst);
	antho_test(env_lst);
 	env_lst_show(env_lst);
	get_input(env_lst);
 	ft_lst_free(env_lst, &env_free);
	return (0);
}
