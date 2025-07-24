NAME = replacer

CXX = c++
CXXFLAGS = -Wextra -Werror -Wall -std=c++98 -Ihpp

SRC_DIR =	src
BUILD_DIR =	.build
DIR_DUP =	@mkdir -p $(@D)

SRCS = 	$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/replacer.cpp

OBJS =	$(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

all: header $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) && echo "${BOLD}${GREEN}Done!${NO_COLOR}" \
	|| echo "${BOLD}${RED}Error compiling $(C_NAME)${NO_COLOR}";

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(DIR_DUP)
	$(CXX) $(CXXFLAGS) -c $< -o $@

header: 
	${info }
	${info ${BOLD}Creating -> ${YELLOW}$(NAME)${NO_COLOR}}
	@if $(MAKE) -q $(NAME) ; then \
		echo "${BOLD}${YELLOW}No changes detected, not rebuilding $(NAME)${NO_COLOR}"; \
	fi

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		rm -rf $(BUILD_DIR) && \
		echo "${BOLD}${GREEN}Deleted build files${NO_COLOR}"; \
	else \
		echo "${BOLD}${YELLOW}No build files to delete${NO_COLOR}"; \
	fi

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME) && \
		echo "${BOLD}${GREEN}Deleted binary file: $(NAME)${NO_COLOR}"; \
	else \
		echo "${BOLD}${YELLOW}No binary file to delete: $(NAME)${NO_COLOR}"; \
	fi
	@if [ -f "tester.sh" ]; then \
		echo && \
		echo "${BOLD}${YELLOW}[Tester]${NO_COLOR}" && \
		./tester.sh fclean && \
		rm -f "tester.sh" && \
		echo "${BOLD}${GREEN}Deleted tester.sh${NO_COLOR}"; \
	fi;

re: fclean all

TESTER_NAME	:= "tester.sh"
TESTER_URL = https://raw.githubusercontent.com/Tegik97/42Cursus/main/Circle_5/cpp/module1/testers/ex04/tester.sh


test:
	@if [ "$(TESTER_URL)" ]; then \
		if [ ! -f "$(TESTER_NAME)" ]; then \
			echo "${BOLD}${YELLOW}Downloading tester...${NO_COLOR}"; \
			curl -sSfL $(TESTER_URL) -o $(TESTER_NAME); \
			if [ -f "$(TESTER_NAME)" ]; then \
				chmod +x $(TESTER_NAME); \
				echo "${BOLD}${GREEN}Done${NO_COLOR}"; \
			else \
				echo "${BOLD}${RED}Not a valid URL: ${NO_COLOR}$(TESTER_URL)"; \
			fi; \
		else \
			echo "${BOLD}${YELLOW}$(TESTER_NAME) already downloaded${NO_COLOR}"; \
		fi; \
	else \
		echo "${BOLD}${RED}URL missing${NO_COLOR}";\
	fi;

.PHONY: all re clean fclean header test
.SILENT:

YELLOW		:= ${shell tput setaf 3}
GREEN		:= ${shell tput setaf 2}
RED			:= ${shell tput setaf 1}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}