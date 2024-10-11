NAME		:= philo
CC			:= cc
CFLAGS		:= -Werror -Wextra -Wall -I./include
RM			:= rm -rf
SRC_DIR		:= src
BUILD_DIR	:= .build
DIR_DUP		:= mkdir -p $(@D)

SRCS		:= $(SRC_DIR)/philosopher.c \
				$(SRC_DIR)/philo_utils.c \
				$(SRC_DIR)/philo_actions.c \
				$(SRC_DIR)/philo_checks.c

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all : header $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(C_NAME)${NO_COLOR}";

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP) $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean: 
	$(RM) $(BUILD_DIR)

fclean: clean
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