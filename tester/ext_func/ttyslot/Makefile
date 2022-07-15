NAME	:=	test_ttyslot

CC	:=	cc
CFLAGS	:=	-MMD -Wall -Werror -Wextra

RM	:=	rm -rf

SRCS	:=	main.c

OBJS	=	$(SRCS:.c=.o)
DEPS	=	$(OBJS:.o=.d)

all:		$(NAME)

%.o:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:
		make clean
		$(RM) $(NAME)

re:
		make fclean
		make all

-include $(DEPS)

.PHONY:		all clean fclean re
