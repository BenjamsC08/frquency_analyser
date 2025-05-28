CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -O3
NAME = prog
SRCS = srcs/hex_parsing.c
OBJ = $(SRCS:.c=.o)
LIB_PATH = -Llibft
LIB_NAME = -lft
INCLUDE_PATH = -Ilibft/includes -Iincludes
VALID = \033[1;32m
NOTVALID = \033[1;31m
LOADING = \033[3;33m
RESET = \033[0m
LIBFT_URL = git@github.com:BenjamsC08/42_00_libft.git

all: libft/libft.a $(NAME)
	@printf "$(VALID) - Done \t\t\t✅$(RESET)\n"

libft/libft.a:
	@test -d libft || (printf "$(LOADING) - libft: cloning repo ... \t⏬$(RESET)\n" && git clone $(LIBFT_URL) libft > /dev/null 2>&1)
	@printf "\r$(LOADING) - libft: compilation ... \t🔃 $(RESET)"
	@$(MAKE) -C libft > /dev/null 2>&1
	@printf "\n$(VALID) - libft: comilation terminée \t✅$(RESET)\n"

srcs/%.o: srcs/%.c
	$(CC) $(FLAGS) $(INCLUDE_PATH) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) $(INCLUDE_PATH) -o $@
	@printf "$(VALID) - $(NAME): compilation terminée \t✅$(RESET)\n"

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft clean > /dev/null 2>&1
	@printf "$(VALID) - clean \t\t\t✅$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean > /dev/null 2>&1
	@printf "$(VALID) - fclean \t\t\t✅$(RESET)\n"

re: fclean all

clist:
	@find -wholename "./srcs/*.c" | cut -c 3- | tr '\n' ' '

cnb:
	@find -wholename "./srcs/*.c" | wc -l

.PHONY: all clean fclean re clist cnb
