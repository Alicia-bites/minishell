# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 09:51:13 by amarchan          #+#    #+#              #
#    Updated: 2022/08/22 17:23:10 by amarchan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:=	libft.a
CC 		:=	cc
CFLAGS		:=	-MMD -Wall -Wextra -Werror
CFLAGSADD	:=	-g3

AR		:=	ar rcs
RM		:=	rm -rf

IPATH		:=	include
OPATH		:=	obj

CHAR_PATH	:=	chartype
CONV_PATH	:=	convert
LIST_PATH	:=	list
MEM_PATH	:=	memory
MSG_PATH	:=	message
PUT_PATH	:=	put
STR_PATH	:=	string
GNL_PATH	:=	get_next_line

CHAR_SRCS	:=	ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isinteger.c\
			ft_ispolarity.c\
			ft_isprint.c\
			ft_isspace.c

CONV_SRCS	:=	ft_atoi.c\
			ft_atoll.c\
			ft_itoa.c\
			ft_tolower.c\
			ft_toupper.c

GNL_SRCS	:= 	get_next_line.c\
				get_next_line_utils.c
			
LIST_SRCS	:=	ft_lst_append.c\
			ft_lst_clear.c\
			ft_lst_delbyobj.c\
			ft_lst_free.c\
			ft_lst_func_lst.c\
			ft_lst_init.c\
			ft_lst_last.c\
			ft_lst_new.c\
			ft_lst_size.c\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lst_delnode.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstnew.c\
			ft_lstsize.c

MEM_SRCS	:=	ft_calloc.c\
			ft_free_ptrptr_str.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c

MSG_SRCS	:=	ft_panic.c\
			ft_panic_null.c\
			ft_panic_value.c\
			ft_shell_msg.c\
			ft_putchar_fd_const.c\
			ft_putstr_fd_const.c\
			ft_putendl_fd_const.c
			

PUT_SRCS	:=	ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c

STR_SRCS	:=	ft_bzero.c\
			ft_index.c\
			ft_left_strip.c\
			ft_right_strip.c\
			ft_split.c\
			ft_strchr.c\
			ft_strchrset_include.c\
			ft_strcmp.c\
			ft_strdup.c\
			ft_strip.c\
			ft_str_isdigit.c\
			ft_str_isll.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strstr.c\
			ft_strstrlen.c\
			ft_strtrim.c\
			ft_substr.c

SRCS		=	$(CHAR_SRCS)\
			$(CONV_SRCS)\
			$(LIST_SRCS)\
			$(MEM_SRCS)\
			$(MSG_SRCS)\
			$(PUT_SRCS)\
			$(STR_SRCS)\
			$(GNL_SRCS)

OBJS		=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
DEPS		=	$(OBJS:.o=.d)

vpath %.h =	$(IPATH)
vpath %.c =	$(CHAR_PATH)\
		$(CONV_PATH)\
		$(LIST_PATH)\
		$(MEM_PATH)\
		$(MSG_PATH)\
		$(PUT_PATH)\
		$(STR_PATH)\
		$(GNL_PATH)
vpath %.o =	$(OPATH)

all:		$(NAME)

$(OPATH)/%.o:	%.c
		$(CC) $(CFLAGS) $(CFLAGSADD) -I $(IPATH) -c $< -o $@

$(NAME):	$(OBJS)
		$(AR) $@ $^

$(OBJS):	| $(OPATH)

$(OPATH):
		mkdir -p $(OPATH)

clean: 
		$(RM) $(OPATH)

fclean:
		make clean
		$(RM) $(NAME)

re:
		make clean
		make all

-include $(DEPS)

.PHONY: bonus all clean fclean re
