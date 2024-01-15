# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 11:31:56 by mchiaram          #+#    #+#              #
#    Updated: 2024/01/11 16:33:14 by mchiaram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f

AR = ar rcs

SRCS = ftprintf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	cd libft && $(MAKE)
	$(AR) $(NAME) libft/*.o
	$(CC) main.c $(NAME) -o a.out

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	$(RM) $(NAME) a.out
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus