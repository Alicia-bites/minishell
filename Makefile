# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:19:37 by amarchan          #+#    #+#              #
#    Updated: 2022/07/18 14:05:05 by amarchan         ###   ########.fr        #
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

SRCS_PATH				:=		srcs
BUILT_PATH				:=		built-in
BUILT_ENV_PATH			:=		do_env
BUILT_UNSET_PATH		:=		do_unset
ENV_PATH				:=		env
EXEC_PATH				:=		execute_commands
INPUT_HANDLER_PATH		:=		input_handler
LEX_PATH				:=		lexer
PARSING_PATH			:=		parsing
EXP_PATH				:=		expansions
SIG_PATH				:=		signal_handling
TOK_PATH				:=		tokenizer
GIVE_CHAR_PATH			:=		give_chartype
GIVE_TOK_PATH			:=		give_type_to_token
MAKE_TOK_PATH			:=		make_token


RM		:=	rm -rf

BUILT_SRCS	:=	cd.c\
				echo.c\
				do_env.c\
				do_env_create_env.c\
				do_env_show.c\
				do_env_update_env.c\
				do_env_update_lst.c\
				do_unset.c\
				do_unset_update_lst.c\
				exit.c\
				export.c\
				pwd.c

ENV_SRCS	:=	env_free.c\
				env_init.c\
				env_init_key.c\
				env_init_value.c\
				env_lst_set.c\
				env_lst_show.c\
				env_show.c

EXEC_SRCS	:=	execute_command.c\
				read_command.c

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
				pre_lexer.c

PARSING_SRCS	:=	count_quotes.c\
					create_list.c\
					create_input_list.c \
					ft_panic.c\
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
				lonely_bracket.c \
				malloc_varname.c \
				print_dollar_lst.c

SIG_SRCS	:=	ft_set_sigaction.c\
				give_prompt_back.c

TOK_SRCS	:=	tokenizer.c\
				
GIVE_CHAR_SRCS	:=	get_chartype.c\
					is_char_space.c\
					is_char_word.c 

GIVE_TOK_SRCS	:=	cmd_heredoc.c\
					cmd_redir.c\
					combo_is_after_pipe.c\
					combo_is_at_the_beggining.c\
					following_pipe.c\
					get_toktype.c\
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
					only_space_in_str.c\
					redir_space_token.c\
					redir_token.c\
					token_redir.c\
					token_space_redir.c

MAKE_TOK_SRCS	:=	add_token_to_list.c\
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
				$(BUILT_SRCS)\
				$(ENV_SRCS)\
				$(EXEC_SRCS)\
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
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_ENV_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_UNSET_PATH)\
	$(SRCS_PATH)/$(ENV_PATH)\
	$(SRCS_PATH)/$(EXEC_PATH)\
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
