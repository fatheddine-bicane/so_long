CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -lXext -lX11
NAME = so_long
BNAME = so_long_bonus

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;31m
RESET = \033[0m

SRCS = 	$(shell ls ./librarys/my_library/libft/*.c) \
		$(shell ls ./librarys/my_library/ft_printf/*.c) \
		$(shell ls ./librarys/my_library/get_next_line/*.c) \
		$(shell ls ./librarys/my_library/perror/*.c) \
		$(shell ls ./error_handling/*.c) \
		$(shell ls ./parce_map/*.c) \
		$(shell ls ./window_managment/*.c) \
		main.c


BONUS =

OFILES = $(SRCS:.c=.o)
BOFILES = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	@$(CC) $(FLAGS) $(OFILES) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)So_long compiled successfully!$(RESET)"


bonus: $(BNAME)

$(BNAME): $(BOFILES)
	@$(CC) $(FLAGS) $(BOFILES) -o $(BNAME)
	@echo "$(GREEN)So_long bonus compiled successfully!$(RESET)"

clean:
	@rm -f $(OFILES) $(BOFILES)
	@echo "$(YELLOW)Cleaning object files$(RESET)"

fclean: clean
	@rm -f $(NAME) $(BNAME)
	@echo "$(YELLOW)Cleaning executables$(RESET)"

re: fclean all

re_bonus : fclean bonus

.PHONY: all bonus clean fclean re
