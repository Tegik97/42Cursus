NAME			:= push_swap
NAME_BONUS		:= checker
LIBFT			:= libft/libft.a
CC				:= cc
CFLAGS			:= -Werror -Wextra -Wall -I./include
LIB				:= ft
RM 				:= rm -rf
SRC_DIR			:= src
SRC_DIR_BONUS	:= src_bonus
BUILD_DIR		:= .build
BUILD_DIR_BONUS	:= .build_bonus
DIR_DUP			:= mkdir -p $(@D)

SRCS		:=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/push_swap.c \
				$(SRC_DIR)/push_swap_checks.c \
				$(SRC_DIR)/push_swap_moves.c \
				$(SRC_DIR)/push_swap_utils.c \
				$(SRC_DIR)/push_swap_algorithm.c \
				$(SRC_DIR)/push_swap_sort.c \
				$(SRC_DIR)/push_swap_sort_back.c \
				$(SRC_DIR)/push_swap_sort_back_sim.c

SRCS_BONUS	:= $(SRC_DIR_BONUS)/main.c \
				$(SRC_DIR_BONUS)/push_swap_bonus.c \
				$(SRC_DIR_BONUS)/push_swap_checks_bonus.c \
				$(SRC_DIR_BONUS)/push_swap_moves_bonus.c \
				$(SRC_DIR_BONUS)/push_swap_utils_bonus.c 

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS	:= $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR_BONUS)/%.o)
LDFLAGS		:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB		:= $(addprefix -l,$(LIB))

all : $(LIBFT) header $(NAME)

bonus: $(LIBFT) header_bonus $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(LIBFT):
	$(MAKE) -C $(@D)
	$(MAKE) bonus -C $(@D)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(DIR_DUP) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean: 
	$(MAKE) clean -C libft
	$(RM) $(BUILD_DIR) $(BUILD_DIR_BONUS)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME) $(NAME_BONUS)

header: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(NAME)${NO_COLOR}}
	@if $(MAKE) -q $(NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
	fi

header_bonus: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(NAME_BONUS)${NO_COLOR}}
	@if $(MAKE) -q $(NAME_BONUS) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME_BONUS)${NO_COLOR}"; \
	fi

.PHONY: all bonus re clean fclean header header_bonus
.SILENT:

YELLOW		:= ${shell tput setaf 3}
GREEN		:= ${shell tput setaf 2}
RED			:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}