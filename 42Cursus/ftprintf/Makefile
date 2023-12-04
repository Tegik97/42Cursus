NAME = libftprintf.a

CC = gcc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f

AR = ar rcs

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)
	
libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft