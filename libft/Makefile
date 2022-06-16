# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 09:51:13 by amarchan          #+#    #+#              #
#    Updated: 2022/06/16 11:24:35 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

FILES =	ft_isalpha \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_strcmp \
	ft_strlen \
	ft_strlcpy \
	ft_strlcat \
	ft_strchr \
	ft_strrchr \
	ft_strnstr \
	ft_strncmp \
	ft_atoi \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_itoa \
	ft_split \
	ft_strmapi \
	ft_striteri \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_isspace \
	ft_rstrip \
	ft_lstrip \
	ft_strip \
	isinteger \
	ft_atoll \
	
FILES_B = 	ft_lstnew \
		ft_lstadd_front \
	  	ft_lstsize \
	  	ft_lstlast \
	  	ft_lstadd_back \
	  	ft_lstdelone \
	  	ft_lstclear \
	  	ft_lstiter \
	  	ft_lstmap \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCS_B)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_B)

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
