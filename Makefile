# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 10:19:37 by amarchan          #+#    #+#              #
#    Updated: 2022/06/16 19:03:43 by amarchan         ###   ########.fr        #
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
		srcs/parsing/sort_inputs.c \
		srcs/parsing/store_built_ins.c \
		srcs/parsing/create_list.c \
		srcs/parsing/print_lst.c \
		srcs/parsing/handle_unknown_command.c \
		srcs/built-in/echo.c \
		srcs/built-in/cd.c \
		srcs/built-in/pwd.c \
		srcs/built-in/export.c \
		srcs/built-in/unset.c \
		srcs/built-in/env.c\
		srcs/built-in/exit.c\
		srcs/execute_commands/read_command.c \
		srcs/execute_commands/execute_command.c \

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