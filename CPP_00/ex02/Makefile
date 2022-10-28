NAME = account

SRCS = Account.cpp tests.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
D_FILES = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

INCS = -I./

COMPILE = c++
C_FLAGS = -g -Wall -Wextra -Werror
STD = -std=c++98

#COLORS
RED 	= 	\033[0;31m
GREEN 	= 	\033[0;32m
BLUE	=	\033[0;34m
BREAK 	= 	\033[0m
YELLOW	=	\033[0;33m

.PHONY : all clean fclean re

all: $(NAME)

$(OBJS_DIR) : 
	@mkdir $@

$(NAME) : $(OBJS)
	$(COMPILE) $(C_FLAGS) $(STD) $(OBJS) -o $@
	@echo "$(BLUE)$(NAME) $(GREEN)--> DONE!$(BREAK)"

$(OBJS_DIR)/%.o : %.cpp | $(OBJS_DIR)
	$(CC) $(C_FLAGS) $(STD) $(INCS) -c $< -o $@ -MD

clean :
	@rm -rf $(OBJS_DIR)
	@echo "$(YELLOW)objs $(RED)DELETED$(BREAK)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(BLUE)$(NAME) $(RED)DELETED$(BREAK)"

re : fclean all

-include $(D_FILES)