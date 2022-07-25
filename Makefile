# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:19:37 by amarchan          #+#    #+#              #
#    Updated: 2022/07/23 13:14:31 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# libft settings
FTPATH		:=	libft
IFT		:=	include
FT_NAME		:=	libft.a
FT		:=	ft

# project settings
NAME 		:=	minishell
NORMINETTE_BIN 	:= 	norminette
NM_BIN		:=	nm
CC		:=	cc
#CFLAGS		:=	-MMD -Wall -Wextra -Werror
CFLAGS		:=	-MMD
#CFLAGSADD	:=	-g3 -fsanitize=address
CFLAGSADD	:=	-g3

VALGRIND	:=	valgrind --suppressions=ignoreliberror --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

IPATH		:=	includes
OPATH		:=	obj

SRCS_PATH				:=	srcs
BUILT_PATH				:=	built-in
BUILT_CD_PATH			:=	do_cd
BUILT_ECHO_PATH			:=	do_echo
BUILT_ENV_PATH			:=	do_env
BUILT_EXIT_PATH			:=	do_exit
BUILT_EXPORT_PATH		:=	do_export
BUILT_PWD_PATH			:=	do_pwd
BUILT_UNSET_PATH		:=	do_unset
CMD_PATH				:=	cmd
ENV_PATH				:=	env
FD_PATH					:=	fd
PIPE_PATH				:=	pipe
INPUT_HANDLER_PATH		:=	input_handler
LEX_PATH				:=	lexer
PARSING_PATH			:=	parsing
EXP_PATH				:=	expansions
SIG_PATH				:=	signal_handling
TOK_PATH				:=	tokenizer
GIVE_CHAR_PATH			:=	give_chartype
GIVE_TOK_PATH			:=	give_type_to_token
MAKE_TOK_PATH			:=	make_token

RM		:=	rm -rf

BUILT_SRCS	:=	do_builtin.c\

BUILT_CD_SRCS	:=	do_cd.c\
			do_cd_home.c\
			do_cd_update_env.c\
			do_cd_update_pwd_home.c

BUILT_ECHO_SRCS	:=	do_echo.c\
			do_echo_n.c

BUILT_ENV_SRCS	:=	do_env.c\
			do_env_show.c

BUILT_EXIT_SRCS	:=	do_exit.c

BUILT_EXPORT_SRCS	:=	do_export.c\
			do_export_create_env.c\
			do_export_check_exist.c\
			do_export_check_str.c\
			do_export_update_env.c\
			do_export_update_lst.c\
			do_export_show.c

BUILT_PWD_SRCS	:=	do_pwd.c\
			do_pwd_getpath.c

BUILT_UNSET_SRCS	:=	do_unset.c\
			do_unset_check_str.c\
			do_unset_update_lst.c\

CMD_SRCS	:=	cmd_create_lst.c\
			cmd_execution.c\
			cmd_free.c\
			cmd_getvalidpath.c\
			cmd_getvalidpath_null.c\
			cmd_init.c\
			cmd_init_prop.c\
			cmd_init_prop_fullcmd.c\
			cmd_init_prop_fullcmd_null.c\
			cmd_init_prop_fullpath.c\
			cmd_init_prop_n_arg.c\
			cmd_loop_envline.c\
			cmd_loop_envp.c\
			cmd_loop_envp_str.c\
			cmd_loop_envp_create_envline.c\
			cmd_setpath.c\
			cmd_show.c

ENV_SRCS	:=	env_free.c\
			env_init.c\
			env_init_key.c\
			env_init_value.c\
			env_init_var_view.c\
			env_lst_set.c\
			env_lst_show.c\
			env_show.c

FD_SRCS		:=	fd_access.c\
			fd_close.c\
			fd_infile_open.c\
			fd_link_in_out_file.c\
			fd_loop_tok.c\
			fd_loop_tok_secure.c\
			fd_loop_tok_type.c\
			fd_open.c\
			fd_outfile_open.c\
			fd_pipe.c\
			fd_pipe_pfd.c

PIPE_SRCS	:=	pipe_close_pfd.c\
			pipe_cmd.c\
			pipe_cmd_dup_fd_in.c\
			pipe_cmd_dup_fd_out.c\
			pipe_exit.c\
			pipe_run.c\
			pipe_wait.c

INPUT_HANDLER	:=	exit_minishell.c\
					get_input.c\
					handle_str.c\
					read_line.c\

LEX_SRCS	:=	lex_brackets.c\
				lex_pipe.c\
				lex_quote.c\
				lex_redir.c\
				lex_space.c\
				lex_sym.c\
				lexer.c

PARSING_SRCS	:=	count_quotes.c\
					create_list.c\
					create_input_list.c \
					handle_unknown_command.c\
					is_not_clone.c\
					is_not_empty.c\
					parsing.c\
					print_lst.c\
					sort_inputs.c\
					store_built_ins.c

EXP_SRCS	:=	bracket_is_after_dollar.c\
				create_dollar_list.c\
				expand_dollar.c\
				find_expansions.c\
				found_operator.c\
				ft_lstadd_back_dollar.c\
				ft_lstclear_back_dollar.c\
				ft_lstclear_dollar.c\
				ft_lstnew_dollar.c\
				get_expanded.c\
				get_full_size.c\
				insert_expansions.c\
				is_varname.c\
				lonely_bracket.c \
				malloc_varname.c \
				print_dollar_lst.c\
				print_global_saved_pos.c\
				save_operator_position.c

SIG_SRCS	:=	ft_set_sigaction.c\
				give_prompt_back.c

TOK_SRCS	:=	tokenizer.c\
				delete_spaces.c\
				
GIVE_CHAR_SRCS	:=	get_chartype.c\
					is_char_space.c\
					is_char_word.c 

GIVE_TOK_SRCS	:=	arg_dlredir_sep_token.c\
					cmd_heredoc.c\
					cmd_redir.c\
					combo_is_after_pipe.c\
					combo_is_at_the_beggining.c\
					following_pipe.c\
					get_toktype.c\
					heredoc_combo_is_after_pipe.c\
					heredoc_combo_is_at_the_beggining.c\
					is_argument.c\
					is_built_in.c\
					is_cmd.c\
					is_combo_heredoc.c\
					is_combo_heredoc_when_heredoc_index_zero.c\
					is_combo_redir.c\
					is_combo_redir_when_redir_index_zero.c\
					is_filename.c\
					is_heredoc_sep.c\
					is_operator.c\
					not_operator.c\
					only_space_in_str.c\
					pipe_cmd_dlredir_sep_token.c\
					redir_space_token.c\
					redir_token.c\
					start_cmd_dlredir_sep_token.c\
					token_redir.c\
					token_space_redir.c

MAKE_TOK_SRCS	:=	add_token_to_list.c\
					built_echo.c\
					built_token.c\
					get_token.c\
					is_bn.c\
					is_dl_redir.c\
					is_d_quote.c\
					is_dr_redir.c\
					is_envcall.c\
					is_intpoint.c\
					is_l_redir.c\
					is_pipe.c\
					is_r_redir.c\
					is_space.c\
					is_s_quote.c\
					is_word.c\
					remove_quotes.c

SRCS		:=	main.c\
			test_antho.c\
				$(BUILT_SRCS)\
				$(BUILT_CD_SRCS)\
				$(BUILT_ECHO_SRCS)\
				$(BUILT_ENV_SRCS)\
				$(BUILT_EXIT_SRCS)\
				$(BUILT_EXPORT_SRCS)\
				$(BUILT_PWD_SRCS)\
				$(BUILT_UNSET_SRCS)\
				$(CMD_SRCS)\
				$(ENV_SRCS)\
				$(EXEC_SRCS)\
				$(FD_SRCS)\
				$(PIPE_SRCS)\
				$(INPUT_HANDLER)\
				$(LEX_SRCS)\
				$(PARSING_SRCS)\
				$(EXP_SRCS)\
				$(SIG_SRCS)\
				$(TOK_SRCS)\
				$(GIVE_CHAR_SRCS)\
				$(GIVE_TOK_SRCS)\
				$(MAKE_TOK_SRCS)\

OBJS		:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS		:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCS_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_CD_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_ECHO_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_ENV_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_EXIT_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_EXPORT_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_PWD_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_UNSET_PATH)\
	$(SRCS_PATH)/$(CMD_PATH)\
	$(SRCS_PATH)/$(ENV_PATH)\
	$(SRCS_PATH)/$(EXEC_PATH)\
	$(SRCS_PATH)/$(FD_PATH)\
	$(SRCS_PATH)/$(PIPE_PATH)\
	$(SRCS_PATH)/$(LEX_PATH)\
	$(SRCS_PATH)/$(INPUT_HANDLER_PATH)\
	$(SRCS_PATH)/$(PARSING_PATH)\
	$(SRCS_PATH)/$(PARSING_PATH)/$(EXP_PATH)\
	$(SRCS_PATH)/$(SIG_PATH)\
	$(SRCS_PATH)/$(TOK_PATH)\
	$(SRCS_PATH)/$(TOK_PATH)/$(GIVE_CHAR_PATH)\
	$(SRCS_PATH)/$(TOK_PATH)/$(GIVE_TOK_PATH)\
	$(SRCS_PATH)/$(TOK_PATH)/$(MAKE_TOK_PATH)
vpath %.o $(OPATH)

all:			$(NAME)

$(OPATH)/%.o:		%.c
			$(CC) $(CFLAGS) $(CFLAGSADD) -I $(IPATH) -I $(FTPATH)/$(IFT) -c $< -o $@

$(NAME):		$(OBJS)
			make -C $(FTPATH)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS) -I $(IPATH) -I $(FTPATH)/$(IFT) -L$(FTPATH) -l$(FT) -lreadline -o $(NAME)

$(OBJS):		| $(OPATH)

$(OPATH):
			mkdir -p $(OPATH)

clean:
			make clean -C $(FTPATH)
			$(RM) $(OPATH)

fclean:
			make clean
			$(RM) $(NAME) $(FT_NAME)
  
re:
			make fclean
			make all

norme:
			$(NORMINETTE_BIN) $(SRCS)

sym:
			$(NM_BIN) -Dgu $(NAME)

comp:
			make
			$(VALGRIND) ./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean re norme sym
