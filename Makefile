NAME = so_long
CC = cc
FLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
RM = rm -rf
LIBFT = library/libft/libft.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lbsd -lXext -lX11 -lm
LIBFT_FLAGS = -L./library/libft -lft

SRCS	=	srcs/so_long.c\
			srcs/error.c\
			srcs/free_and_close.c\
			srcs/malloc_map.c\
			srcs/parsing_map.c\
			srcs/parsing_path.c\
			srcs/player_move.c\
			srcs/player_move2.c\
			srcs/show_map.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS)

$(LIBFT):
	make -C library/libft

minilibx :
	@git clone "https://github.com/42Paris/minilibx-linux.git"
	cd minilibx-linux && make

.c.o:
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@make -s -C library/libft clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C library/libft fclean

re: fclean all

.PHONY: all clean fclean re bonus minilibx