NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
D_FILES = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

INCS_DIR = ./
INCS = -I$(INCS_DIR)

COMPILE = c++
C_FLAGS = -g -Wall -Wextra -Werror
STD = -std=c++98
SANIT_FLAGS = -fsanitize=address

#COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
BREAK 	= 	\033[0m
YELLOW	=	\033[0;33m

.PHONY : all clean fclean re sanit leaks

all: $(NAME)

$(OBJS_DIR) : 
	@mkdir $@

$(NAME) : $(OBJS)
	$(COMPILE) $(C_FLAGS) $(STD) $(OBJS) -o $@
	@echo "$(BLUE)$(NAME) $(GREEN)--> DONE!$(BREAK)"

$(OBJS_DIR)/%.o : %.cpp | $(OBJS_DIR)
	$(COMPILE) $(C_FLAGS) $(STD) $(INCS) -c $< -o $@ -MD

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(YELLOW)objs $(RED)DELETED$(BREAK)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(BLUE)$(NAME) $(RED)DELETED$(BREAK)"

re : fclean all

sanit:
	make
	$(COMPILE) $(SANIT_FLAGS) $(C_FLAGS) $(OBJS) -o $(NAME)

leaks :
	make
	leaks -atExit -- ./$(NAME)

-include $(D_FILES)