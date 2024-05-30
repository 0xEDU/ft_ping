NAME = ft_ping
PATH_SRCS = ./src/
PATH_OBJS = ./obj/

SRCS = main.c \
	   print_help.c \
	   calculate_checksum.c

OBJS = ${SRCS:%.c=$(PATH_OBJS)%.o}

INCLUDE = -I ./incl/
FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

run: all
	@./$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@cc $(FLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[1;92m[SUCCESS] Object" $< "created!\033[0m"

clean:
	@rm -rf $(PATH_OBJS)
	@echo "\33[1;93m[SUCCESS] Objects removed!\33[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;93m[SUCCESS] Binary removed!\33[0m"

re: fclean all
	
.PHONY: all clean fclean re

