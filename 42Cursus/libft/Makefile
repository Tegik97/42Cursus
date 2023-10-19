# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:19:10 by mchiaram          #+#    #+#              #
#    Updated: 2023/10/19 18:35:42 by mchiaram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Werror -Wall
SRC = ft_atoi.c / 
	ft_bzero.c /
	ft_calloc.c /
	ft_isalnum.c /
	ft_isalpha.c /
	ft_isascii.c /
	ft_isdigit.c /
	ft_isprint.c /
	ft_itoa.c /
	ft_memchr.c /
	ft_memcmp.c /
	ft_memcpy.c /
	ft_memmove.c /
	ft_memset.c /
	ft_split.c /
	ft_strchr.c /
	ft_strdup.c /
	ft_strjoin.c /
	ft_strlcat.c /
	ft_strlcpy.c /
	ft_strlen.c /
	ft_strncmp.c /
	ft_strnstr.c /
	ft_strrchr.c /
	ft_strtrim.c /
	ft_substr.c /
	ft_tolower.c /
	ft_toupper.c /
	
OBJ = $(SRC:.c=.o)
TARGET = libft.a

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

re: clean fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean re
