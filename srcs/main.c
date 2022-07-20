/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:17:17 by amarchan          #+#    #+#             */
/*   Updated: 2022/07/20 11:04:38 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	antho_test(t_ulist **env_lst)
{
	int	case_cd;
	int	case_env;
	int	case_export;
	int	case_unset;

	case_cd = 0;
	case_env = 1;
	case_export = 1;
	case_unset = 1;

 	t_cmd	test_env_cmd;
	char test_env_cmd_arg[] = "env";
	char *test_env_cmd_fullcmd[] = { "env", NULL };
// 	char test_env_cmd_arg[] = "env ANTHO=toto";
// 	char *test_env_cmd_fullcmd[] = { "env", "ANTHO=toto", NULL };
//	char test_env_cmd_arg[] = "env ANTHO=toto echo $ANTHO";
//	char *test_env_cmd_fullcmd[] = { "env", "ANTHO=toto", "echo", "$ANTHO", NULL };
//	char test_env_cmd_arg[] = "env echo $ANTHO";
//	char *test_env_cmd_fullcmd[] = { "env", "echo", "$ANTHO", NULL };
 	char test_env_cmd_path[] = "built-in";

 	test_env_cmd.arg = test_env_cmd_arg;
 	test_env_cmd.fullcmd = test_env_cmd_fullcmd;
 	test_env_cmd.fullpath = test_env_cmd_path;
	if (case_env)
	{
		do_env(env_lst, &test_env_cmd);
		ft_lst_func_lst(env_lst, &do_export_show);
		ft_lst_func_lst(env_lst, &do_env_show);
		printf("%s\n", SEP_P);
	}

 	t_cmd	test_export_cmd;
// 	char test_export_cmd_arg[] = "export";
// 	char *test_export_cmd_fullcmd[] = { "export", NULL };
 	char test_export_cmd_arg[] = "export ANTHO=toto=";
	char *test_export_cmd_fullcmd[] = { "export", "ANTHO=toto", NULL };
// 	char test_export_cmd_arg[] = "export ANTHO ANTHO=toto=titi=tata ANTHO ALICIA=BG @ELON ANTHO=";
//	char *test_export_cmd_fullcmd[] = { "export", "ANTHO", "ANTHO=toto=titi=tata", "ANTHO", "ALICIA=BG", "@ELON", "ANTHO=", NULL };
//	char test_export_cmd_arg[] = "export ANTHO={echo -n}";
//	char *test_export_cmd_fullcmd[] = { "export", "ANTHO", "{echo -n}", NULL };
	char test_export_cmd_path[] = "built-in";

 	test_export_cmd.arg = test_export_cmd_arg;
 	test_export_cmd.fullcmd = test_export_cmd_fullcmd;
 	test_export_cmd.fullpath = test_export_cmd_path;
	if (case_export)
	{
		do_export(env_lst, &test_export_cmd);
		ft_lst_func_lst(env_lst, &do_export_show);
		ft_lst_func_lst(env_lst, &do_env_show);
		printf("%s\n", SEP_P);
	}

 	t_cmd	test_unset_cmd;
// 	char test_unset_cmd_arg[] = "unset";
// 	char *test_unset_cmd_fullcmd[] = { "unset", NULL };
	char test_unset_cmd_arg[] = "unset ANTHO";
	char *test_unset_cmd_fullcmd[] = { "unset", "ANTHO", NULL };
 	char test_unset_cmd_path[] = "built-in";

 	test_unset_cmd.arg = test_unset_cmd_arg;
 	test_unset_cmd.fullcmd = test_unset_cmd_fullcmd;
 	test_unset_cmd.fullpath = test_unset_cmd_path;
	if (case_unset)
	{
		do_unset(env_lst, &test_unset_cmd);
		ft_lst_func_lst(env_lst, &do_export_show);
		ft_lst_func_lst(env_lst, &do_env_show);
		printf("%s\n", SEP_P);
	}

 	t_cmd	test_cd_cmd;
// 	char test_cd_cmd_arg[] = "cd";
// 	char *test_cd_cmd_fullcmd[] = { "cd", NULL };
// 	char test_cd_cmd_arg[] = "cd dir_which_does_not_exist";
// 	char *test_cd_cmd_fullcmd[] = { "cd", "dir_which_does_not_exist", NULL };
 	char test_cd_cmd_arg[] = "cd too many arg" ;
 	char *test_cd_cmd_fullcmd[] = { "cd", "too", "many", "arg", NULL };
 	char test_cd_cmd_path[] = "built-in";

	test_cd_cmd.arg = test_cd_cmd_arg;
 	test_cd_cmd.fullcmd = test_cd_cmd_fullcmd;
 	test_cd_cmd.fullpath = test_cd_cmd_path;
	if (case_cd)
	{
		do_cd(env_lst, &test_cd_cmd);
		ft_lst_func_lst(env_lst, &do_export_show);
		ft_lst_func_lst(env_lst, &do_env_show);
		printf("%s\n", SEP_P);
	}
}

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
//	antho_test(env_lst);
// 	env_lst_show(env_lst);
	get_input(&err, env_lst);
 	ft_lst_free(env_lst, &env_free);
	return (0);
}
