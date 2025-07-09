NAME		:= cub3d
LIBFT		:= libft/libft.a
CC			:= gcc -g
CFLAGS		:= -Wall -Werror -Wextra -I./include
RM			:= rm -rf
LIB			:= ft
SRC_DIR		:= src
BUILD_DIR	:= .build
DIR_MKD		:= mkdir -p
INCLUDES 	:= -I/usr/include -Imlx_linux
MLX_FLAGS	:= -L./mlx_linux -lmlx -lXext -lX11 -lm

SRCS	:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/keys.c \
				$(SRC_DIR)/rays.c \
				$(SRC_DIR)/draw.c \
				$(SRC_DIR)/mouse.c \
				$(SRC_DIR)/minimap.c \
				$(SRC_DIR)/texture.c \
				$(SRC_DIR)/movements.c \
				$(SRC_DIR)/init_struct.c \
				$(SRC_DIR)/parsing/tmp_main/parse_init.c \
				$(SRC_DIR)/parsing/cub_parsing/cub_check.c \
				$(SRC_DIR)/parsing/path_parsing/texture_path.c \
				$(SRC_DIR)/parsing/path_parsing/missing_path_print.c \
				$(SRC_DIR)/parsing/map_parsing/map_parsing.c \
				$(SRC_DIR)/parsing/map_parsing/check_map_validity.c \
				$(SRC_DIR)/parsing/map_parsing/check_enclosed_map.c \
				$(SRC_DIR)/parsing/utility/free_mem.c \
				$(SRC_DIR)/parsing/utility/print_error.c

OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LDFLAGS		:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB		:= $(addprefix -l,$(LIB))

all	: $(LIBFT) header $(NAME)

$(NAME): $(OBJS) $(LIBFT)
			$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ $(MLX_FLAGS) \
		&& echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(LIBFT):
	$(MAKE) -C $(@D)
	$(MAKE) bonus -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			$(DIR_MKD) $(@D)
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
		$(MAKE) clean -C libft
		$(RM) $(BUILD_DIR)

fclean: clean
		$(MAKE) fclean -C libft
		$(RM) $(NAME)

re: fclean all


header: 
	${info }
	${info ${BOLD}Creating  ->${YELLOW}$(NAME)${NO_COLOR}}
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

