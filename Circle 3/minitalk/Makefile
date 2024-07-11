C_NAME		:= client
S_NAME		:= server
CB_NAME		:= client_bonus
SB_NAME		:= server_bonus
LIBFT		:= libft/libft.a
CC			:= gcc -g
CFLAGS		:= -Werror -Wextra -Wall -I./include
LIB			:= ft
RM			:= rm -rf
SRC_DIR		:= src
BUILD_DIR	:= .build
DIR_DUP		:= mkdir -p $(@D)

SRCS_CLIENT		:= $(SRC_DIR)/client.c
SRCS_CLIENTB	:= $(SRC_DIR)/client_bonus.c

SRCS_SERVER		:= $(SRC_DIR)/server.c
SRCS_SERVERB	:= $(SRC_DIR)/server_bonus.c

OBJS_CLIENT		:= $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_SERVER		:= $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLIENTB	:= $(SRCS_CLIENTB:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_SERVERB	:= $(SRCS_SERVERB:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LDFLAGS		:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB		:= $(addprefix -l,$(LIB))

all : $(LIBFT) header_client $(C_NAME) header_server $(S_NAME)

bonus : $(LIBFT) header_client_bonus $(CB_NAME) header_server_bonus $(SB_NAME)

$(C_NAME): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(C_NAME)${NO_COLOR}";

$(S_NAME): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(S_NAME)${NO_COLOR}";

$(CB_NAME): $(OBJS_CLIENTB) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(C_NAME)${NO_COLOR}";

$(SB_NAME): $(OBJS_SERVERB) $(LIBFT)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(S_NAME)${NO_COLOR}";

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
	$(RM) $(C_NAME)
	$(RM) $(S_NAME)
	$(RM) $(CB_NAME)
	$(RM) $(SB_NAME)

header_client: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(C_NAME)${NO_COLOR}}
	@if $(MAKE) -q $(C_NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(C_NAME)${NO_COLOR}"; \
	fi

header_server: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(S_NAME)${NO_COLOR}}
	@if $(MAKE) -q $(S_NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(S_NAME)${NO_COLOR}"; \
	fi

header_client_bonus: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(CB_NAME)${NO_COLOR}}
	@if $(MAKE) -q $(CB_NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(CB_NAME)${NO_COLOR}"; \
	fi

header_server_bonus: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(SB_NAME)${NO_COLOR}}
	@if $(MAKE) -q $(SB_NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(SB_NAME)${NO_COLOR}"; \
	fi

.PHONY: all re clean fclean header_client header_server
.SILENT:

YELLOW		:= ${shell tput setaf 3}
GREEN		:= ${shell tput setaf 2}
RED			:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}