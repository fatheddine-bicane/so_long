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

SRCS =	./my_library/libft/ft_atoi.c ./my_library/libft/ft_bzero.c ./my_library/libft/ft_calloc.c ./my_library/libft/ft_isalnum.c ./my_library/libft/ft_isalpha.c ./my_library/libft/ft_isascii.c ./my_library/libft/ft_isdigit.c ./my_library/libft/ft_isprint.c ./my_library/libft/ft_itoa.c ./my_library/libft/ft_lstadd_back_bonus.c ./my_library/libft/ft_lstadd_front_bonus.c ./my_library/libft/ft_lstclear_bonus.c ./my_library/libft/ft_lstdelone_bonus.c ./my_library/libft/ft_lstiter_bonus.c ./my_library/libft/ft_lstlast_bonus.c ./my_library/libft/ft_lstmap_bonus.c ./my_library/libft/ft_lstnew_bonus.c ./my_library/libft/ft_lstsize_bonus.c ./my_library/libft/ft_memchr.c ./my_library/libft/ft_memcmp.c ./my_library/libft/ft_memcpy.c ./my_library/libft/ft_memmove.c ./my_library/libft/ft_memset.c ./my_library/libft/ft_putchar_fd.c ./my_library/libft/ft_putendl_fd.c ./my_library/libft/ft_putnbr_fd.c ./my_library/libft/ft_putstr_fd.c ./my_library/libft/ft_split.c ./my_library/libft/ft_strchr.c ./my_library/libft/ft_strdup.c ./my_library/libft/ft_striteri.c ./my_library/libft/ft_strjoin.c ./my_library/libft/ft_strlcat.c ./my_library/libft/ft_strlcpy.c ./my_library/libft/ft_strlen.c ./my_library/libft/ft_strmapi.c ./my_library/libft/ft_strncmp.c ./my_library/libft/ft_strnstr.c ./my_library/libft/ft_strrchr.c ./my_library/libft/ft_strtrim.c ./my_library/libft/ft_substr.c ./my_library/libft/ft_tolower.c ./my_library/libft/ft_toupper.c ./my_library/ft_printf/ft_nb_count.c ./my_library/ft_printf/ft_printf.c ./my_library/ft_printf/ft_putadrr.c ./my_library/ft_printf/ft_putchar.c ./my_library/ft_printf/ft_puthexa.c ./my_library/ft_printf/ft_putnbr.c ./my_library/ft_printf/ft_putstr.c ./my_library/ft_printf/ft_putunint.c ./my_library/get_next_line/get_next_line.c ./my_library/perror/ft_perror.c so_long.c main.c read_map.c error_handling.c

BONUS =	./my_library/libft/ft_atoi.c ./my_library/libft/ft_bzero.c ./my_library/libft/ft_calloc.c ./my_library/libft/ft_isalnum.c ./my_library/libft/ft_isalpha.c ./my_library/libft/ft_isascii.c ./my_library/libft/ft_isdigit.c ./my_library/libft/ft_isprint.c ./my_library/libft/ft_itoa.c ./my_library/libft/ft_lstadd_back_bonus.c ./my_library/libft/ft_lstadd_front_bonus.c ./my_library/libft/ft_lstclear_bonus.c ./my_library/libft/ft_lstdelone_bonus.c ./my_library/libft/ft_lstiter_bonus.c ./my_library/libft/ft_lstlast_bonus.c ./my_library/libft/ft_lstmap_bonus.c ./my_library/libft/ft_lstnew_bonus.c ./my_library/libft/ft_lstsize_bonus.c ./my_library/libft/ft_memchr.c ./my_library/libft/ft_memcmp.c ./my_library/libft/ft_memcpy.c ./my_library/libft/ft_memmove.c ./my_library/libft/ft_memset.c ./my_library/libft/ft_putchar_fd.c ./my_library/libft/ft_putendl_fd.c ./my_library/libft/ft_putnbr_fd.c ./my_library/libft/ft_putstr_fd.c ./my_library/libft/ft_split.c ./my_library/libft/ft_strchr.c ./my_library/libft/ft_strdup.c ./my_library/libft/ft_striteri.c ./my_library/libft/ft_strjoin.c ./my_library/libft/ft_strlcat.c ./my_library/libft/ft_strlcpy.c ./my_library/libft/ft_strlen.c ./my_library/libft/ft_strmapi.c ./my_library/libft/ft_strncmp.c ./my_library/libft/ft_strnstr.c ./my_library/libft/ft_strrchr.c ./my_library/libft/ft_strtrim.c ./my_library/libft/ft_substr.c ./my_library/libft/ft_tolower.c ./my_library/libft/ft_toupper.c ./my_library/ft_printf/ft_nb_count.c ./my_library/ft_printf/ft_printf.c ./my_library/ft_printf/ft_putadrr.c ./my_library/ft_printf/ft_putchar.c ./my_library/ft_printf/ft_puthexa.c ./my_library/ft_printf/ft_putnbr.c ./my_library/ft_printf/ft_putstr.c ./my_library/ft_printf/ft_putunint.c ./my_library/get_next_line/get_next_line.c ./my_library/perror/ft_perror.c

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
