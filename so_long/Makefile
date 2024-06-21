# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiaram <mchiaram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/21 11:25:57 by mchiaram          #+#    #+#              #
#    Updated: 2024/06/21 11:25:58 by mchiaram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
LIBFT		:= libft/libft.a
CC			:= cc
CFLAGS		:= -Werror -Wextra -Wall -I./include
LIB			:= ft
RM			:= rm -rf
SRC_DIR		:= src
BUILD_DIR	:= .build
DIR_DUP		:= mkdir -p $(@D)
INCLUDES 	:= -I/usr/include -Imlx_linux
MLX_FLAGS	:= -L./mlx_linux -lmlx -L/usr/lib/X11 -lXext -lX11

SRCS		:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/so_long.c \
				$(SRC_DIR)/so_long_parsing.c \
				$(SRC_DIR)/so_long_wall_parsing.c \
				$(SRC_DIR)/so_long_floodfill.c \
				$(SRC_DIR)/so_long_utils.c \
				$(SRC_DIR)/so_long_put_image.c \
				$(SRC_DIR)/so_long_search_str_image.c \
				$(SRC_DIR)/so_long_frame_update.c \
				$(SRC_DIR)/so_long_move.c \
				$(SRC_DIR)/so_long_put_moves.c 

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LDFLAGS		:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB		:= $(addprefix -l,$(LIB))

all : $(LIBFT) header $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ $(MLX_FLAGS) && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(LIBFT):
	$(MAKE) -C $(@D)
	$(MAKE) bonus -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP) $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

re: fclean all

clean: 
	$(MAKE) clean -C libft
	$(RM) $(BUILD_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

header: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(NAME)${NO_COLOR}}
	@if $(MAKE) -q $(NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
	fi

.PHONY: all re clean fclean header
.SILENT:

YELLOW		:= ${shell tput setaf 3}
GREEN		:= ${shell tput setaf 2}
RED			:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}