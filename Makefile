# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:19:37 by amarchan          #+#    #+#              #
#    Updated: 2022/07/06 15:10:56 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

NAME_LIBFT = libft.a

NORMINETTE_BIN = norminette

NM_BIN = nm

DIR_LIBFT = libft/

SRCS =	srcs/main.c \
		srcs/parsing/parsing.c \
		srcs/parsing/ft_panic.c \
		srcs/parsing/create_input_list.c \
		srcs/parsing/sort_inputs.c \
		srcs/parsing/store_built_ins.c \
		srcs/parsing/create_list.c \
		srcs/parsing/print_lst.c \
		srcs/parsing/is_not_clone.c \
		srcs/parsing/is_not_empty.c \
		srcs/parsing/count_quotes.c \
		srcs/lexer/lexer.c \
		srcs/lexer/lex_pipe.c \
		srcs/lexer/lex_quote.c \
		srcs/lexer/lex_redir.c \
		srcs/lexer/lex_sym.c \
		srcs/parsing/handle_unknown_command.c \
		srcs/parsing/expansions/create_dollar_list.c \
		srcs/parsing/expansions/find_expansions.c \
		srcs/parsing/expansions/ft_lstclear_dollar.c \
		srcs/parsing/expansions/ft_lstclear_back_dollar.c \
		srcs/parsing/expansions/get_expanded.c \
		srcs/parsing/expansions/insert_expansions.c \
		srcs/parsing/expansions/print_dollar_lst.c \
		srcs/parsing/expansions/expand_dollar.c \
		srcs/parsing/expansions/ft_lstadd_back_dollar.c \
		srcs/parsing/expansions/ft_lstnew_dollar.c \
		srcs/parsing/expansions/get_full_size.c \
		srcs/parsing/expansions/malloc_varname.c \
		srcs/parsing/expansions/is_varname.c \
		srcs/built-in/echo.c \
		srcs/built-in/cd.c \
		srcs/built-in/pwd.c \
		srcs/built-in/export.c \
		srcs/built-in/unset.c \
		srcs/built-in/env.c\
		srcs/built-in/exit.c\
		srcs/execute_commands/read_command.c \
		srcs/execute_commands/execute_command.c \
		srcs/tokenizer/tokenizer.c \
		srcs/tokenizer/is_space.c \
		srcs/tokenizer/is_pipe.c \
		srcs/tokenizer/is_s_quote.c \
		srcs/tokenizer/is_d_quote.c \
		srcs/tokenizer/is_envcall.c \
		srcs/tokenizer/is_l_redir.c \
		srcs/tokenizer/is_r_redir.c \
		srcs/tokenizer/is_dl_redir.c \
		srcs/tokenizer/is_dr_redir.c \
		srcs/tokenizer/is_bn.c \
		srcs/tokenizer/is_intpoint.c \
		srcs/tokenizer/is_word.c \
		srcs/tokenizer/get_chartype.c \
		srcs/tokenizer/get_token.c \
		srcs/tokenizer/built_token.c \
		srcs/tokenizer/remove_quotes.c \
		srcs/tokenizer/add_token_to_list.c \
		srcs/tokenizer/is_char_word.c \
		srcs/tokenizer/get_toktype.c \
		srcs/tokenizer/is_char_space.c \
		srcs/tokenizer/is_operator.c \
		srcs/tokenizer/only_space_in_str.c \
		srcs/signal_handling/ft_set_sigaction.c \
		srcs/signal_handling/give_prompt_back.c \

CC = clang

OBJS := ${SRCS:.c=.o}

CFLAGS = -g3

RM = rm -rf

INC_DIR = includes

INC_LIBFT = libft

.c.o: $(SRCS) minishell.h
	$(CC) $(CFLAGS) -c -I ${INC_DIR} -I ${INC_LIBFT} $< -o ${<:.c=.o}

all: $(NAME_LIBFT) $(NAME) 

$(NAME_LIBFT):
	make -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)libft.a .
	
$(NAME): ${OBJS}
	$(CC) $(CFLAGS) -lreadline -o $(NAME) $(OBJS) $(NAME_LIBFT)

clean:
	${RM} ${OBJS}
	make -C $(DIR_LIBFT) clean

fclean:
	make clean
	$(RM) $(NAME) ${NAME_LIBFT} 
  
re:
	make fclean
	make all

norme:
	${NORMINETTE_BIN} ${SRCS}

sym:
	${NM_BIN} -Dgu $(NAME)

.PHONY: all clean fclean re norme sym