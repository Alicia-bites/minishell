# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:19:37 by amarchan          #+#    #+#              #
#    Updated: 2022/07/18 13:23:31 by abarrier         ###   ########.fr        #
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

VALGRIND	:=	valgrind --suppressions=ignoreliberror --leak-check=full --show-leak-kinds=all --track-origins=yes

IPATH		:=	includes
OPATH		:=	obj

SRCS_PATH	:=	srcs
BUILT_PATH	:=	built-in
BUILT_CD_PATH	:=	do_cd
BUILT_ECHO_PATH	:=	do_echo
BUILT_ENV_PATH	:=	do_env
BUILT_EXIT_PATH	:=	do_exit
BUILT_EXPORT_PATH	:=	do_export
BUILT_PWD_PATH	:=	do_pwd
BUILT_UNSET_PATH	:=	do_unset
CMD_PATH	:=	cmd
ENV_PATH	:=	env
EXEC_PATH	:=	execute_commands
LEX_PATH	:=	lexer
PARSING_PATH	:=	parsing
EXP_PATH	:=	expansions
SIG_PATH	:=	signal_handling
TOK_PATH	:=	tokenizer

RM		:=	rm -rf

BUILT_CD_SRCS	:=	do_cd.c

BUILT_ECHO_SRCS	:=	do_echo.c

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

BUILT_PWD_SRCS	:=	do_pwd.c

BUILT_UNSET_SRCS	:=	do_unset.c\
			do_unset_check_str.c\
			do_unset_update_lst.c\

CMD_SRCS	:=	cmd_close_fd.c\
			cmd_create_lst.c\
			cmd_free.c\
			cmd_getvalidpath.c\
			cmd_getvalidpath_null.c\
			cmd_init.c\
			cmd_init_prop.c\
			cmd_init_prop_fullcmd.c\
			cmd_init_prop_fullcmd_null.c\
			cmd_init_prop_n_arg.c\
			cmd_loop_envline.c\
			cmd_loop_envp.c\
			cmd_loop_envp_str.c\
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

EXEC_SRCS	:=	execute_command.c\
			read_command.c

LEX_SRCS	:=	lex_brackets.c \
				lex_pipe.c \
				lex_quote.c \
				lex_redir.c \
				lex_sym.c \
				pre_lexer.c

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

EXP_SRCS	:=	create_dollar_list.c\
			expand_dollar.c\
			find_expansions.c\
			ft_lstadd_back_dollar.c\
			ft_lstclear_back_dollar.c\
			ft_lstclear_dollar.c\
			ft_lstnew_dollar.c\
			get_expanded.c\
			get_full_size.c\
			insert_expansions.c\
			is_varname.c\
			malloc_varname.c\
			print_dollar_lst.c

SIG_SRCS	:=	ft_set_sigaction.c \
				give_prompt_back.c

TOK_SRCS	:=	add_token_to_list.c \
				built_token.c \
				get_chartype.c \
				get_token.c \
				get_toktype.c \
				is_bn.c \
				is_char_space.c \
				is_char_word.c \
				is_dl_redir.c \
				is_d_quote.c \
				is_dr_redir.c \
				is_envcall.c \
				is_intpoint.c \
				is_l_redir.c \
				is_operator.c \
				is_pipe.c \
				is_r_redir.c \
				is_space.c \
				is_s_quote.c \
				is_word.c \
				only_space_in_str.c \
				print_token.c \
				remove_quotes.c \
				tokenizer.c

SRCS		:=	main.c\
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
			$(LEX_SRCS)\
			$(PARSING_SRCS)\
			$(EXP_SRCS)\
			$(SIG_SRCS)\
			$(TOK_SRCS)\

OBJS		:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS		:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCS_PATH)\
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
	$(SRCS_PATH)/$(LEX_PATH)\
	$(SRCS_PATH)/$(PARSING_PATH)\
	$(SRCS_PATH)/$(PARSING_PATH)/$(EXP_PATH)\
	$(SRCS_PATH)/$(SIG_PATH)\
	$(SRCS_PATH)/$(TOK_PATH)
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
