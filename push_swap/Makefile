NAME		:= push_swap
LIBFT		:= libft/libft.a
CC			:= gcc -g
CFLAGS		:= -Werror -Wextra -Wall
INCS		:= ./include
LIB			:= ft
RM 			:= rm -f

SRCS		:=	main.c \
				push_swap.c \
				push_swap_checks.c \
				push_swap_moves.c \
				push_swap_utils.c \
				push_swap_algorithm.c \
				push_swap_sort.c \
				push_swap_sort_sim.c
				
OBJS		:= $(SRCS:.c=.o)
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L,$(dir $(LIBFT)))
LDLIB		:= $(addprefix -l,$(LIB))

all : $(LIBFT) header $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@ && echo "${BOLD}${GREEN}Done!${NO_COLOR}" || echo "${BOLD}${RED}Error compiling $(NAME)${NO_COLOR}";

$(LIBFT):
	$(MAKE) -C $(@D)
	$(MAKE) bonus -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

re: fclean all

clean: 
	$(MAKE) clean -C libft
	$(RM) $(OBJS) *.d

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