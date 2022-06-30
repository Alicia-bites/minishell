# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:19:37 by amarchan          #+#    #+#              #
#    Updated: 2022/06/30 15:54:11 by antho            ###   ########.fr        #
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
CFLAGSADD	:=	-g3

IPATH		:=	includes
OPATH		:=	obj

SRCS_PATH	:=	srcs
BUILT_PATH	:=	built-in
BUILT_ENV_PATH	:=	do_env
ENV_PATH	:=	env
EXEC_PATH	:=	execute_commands
PARSING_PATH	:=	parsing
EXP_PATH	:=	expansions
TOK_PATH	:=	tokenizer

RM		:=	rm -rf

BUILT_SRCS	:=	cd.c\
			echo.c\
			do_env.c\
			do_env_show.c\
			exit.c\
			export.c\
			pwd.c\
			unset.c

ENV_SRCS	:=	env_free.c\
			env_init.c\
			env_init_key.c\
			env_init_value.c\
			env_lst_set.c\
			env_lst_show.c\
			env_show.c

EXEC_SRCS	:=	execute_command.c\
			read_command.c

PARSING_SRCS	:=	count_quotes.c\
			create_list.c\
			ft_panic.c\
			handle_unknown_command.c\
			is_not_clone.c\
			is_not_empty.c\
			parsing.c\
			print_lst.c\
			sort_inputs.c\
			store_built_ins.c\

EXP_SRCS	:=	create_dollar_list.c\
			expand_dollar.c\
			find_expansions.c\
			ft_lstadd_back_dollar.c\
			ft_lstclear_back.c\
			ft_lstclear_dollar.c\
			ft_lstnew_dollar.c\
			get_expanded.c\
			get_full_size.c\
			insert_expansions.c\
			is_varname.c\
			malloc_varname.c\
			print_dollar_lst.c

TOK_SRCS	:=	is_bn.c\
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
			tokenizer.c

SRCS		:=	main.c\
			$(BUILT_SRCS)\
			$(ENV_SRCS)\
			$(EXEC_SRCS)\
			$(PARSING_SRCS)\
			$(EXP_SRCS)\
			$(TOK_SRCS)\

#SRCS 		:=	main.c \
#			parsing.c \
#			ft_panic.c \
#			sort_inputs.c \
#			store_built_ins.c \
#			create_list.c \
#			print_lst.c \
#			is_not_clone.c \
#			is_not_empty.c \
#			count_quotes.c \
#			handle_unknown_command.c \
#			create_dollar_list.c \
#			find_expansions.c \
#			ft_lstclear_dollar.c \
#			ft_lstclear_back.c \
#			get_expanded.c \
#			insert_expansions.c \
#			print_dollar_lst.c \
#			expand_dollar.c \
#			ft_lstadd_back_dollar.c \
#			ft_lstnew_dollar.c \
#			get_full_size.c \
#			malloc_varname.c \
#			is_varname.c \
#			echo.c \
#			cd.c \
#			pwd.c \
#			export.c \
#			unset.c \
#			env.c\
#			exit.c\
#			ead_command.c \
#			execute_command.c \
#			tokenizer.c \
#			is_space.c \
#			is_pipe.c \
#			is_s_quote.c \
#			is_d_quote.c \
#			is_envcall.c \
#			is_l_redir.c \
#			is_r_redir.c \
#			is_dl_redir.c \
#			is_dr_redir.c \
#			is_bn.c \
#			is_intpoint.c \
#			is_word.c \

OBJS		:=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS		:=	$(OBJS:.o=.d)

vpath %.h $(IPATH)
vpath %.c $(SRCS_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)\
	$(SRCS_PATH)/$(BUILT_PATH)/$(BUILT_ENV_PATH)\
	$(SRCS_PATH)/$(ENV_PATH)\
	$(SRCS_PATH)/$(EXEC_PATH)\
	$(SRCS_PATH)/$(PARSING_PATH)\
	$(SRCS_PATH)/$(PARSING_PATH)/$(EXP_PATH)\
	$(SRCS_PATH)/$(TOK_PATH)
vpath %.o $(OPATH)

all:			$(NAME)

$(OPATH)/%.o:		%.c
			$(CC) $(CFLAGS) $(CFLAGSADD) -I $(IPATH) -I $(FTPATH)/$(IFT) -c $< -o $@

$(NAME):		$(OBJS)
			make -C $(FTPATH)
			$(CC) $(CFLAGS) $(CFLAGSADD) $(OBJS) -I $(IPATH) -I $(FTPATH)/$(IFT) -L$(FTPATH) -l$(FT) -o $(NAME)

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

-include $(DEPS)

.PHONY: all clean fclean re norme sym
