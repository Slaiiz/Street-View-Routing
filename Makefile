NAME	= street_view_routing
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= main.c tools.c solve.c
OBJS	= $(subst .c,.o,$(SRCS))

all: $(NAME)

$(NAME):
	cd srcs/;\
	$(CC) $(CFLAGS) -I ../includes/ -o ../$(NAME) $(SRCS)

clean:
	cd srcs/;\
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
