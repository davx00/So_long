NAME=so_long
CC=cc
MLX_DIR = minilibx-linux
LIBFT_DIR = libft
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -Iminilibx-linux -Ilibft
LFLAGS = -Lminilibx-linux -lmlx_Linux -Llibft -lft -lXext -lX11 -lm -lz

SRC=	./proyects/so_long.c \
    ./proyects/read_map.c \
    ./proyects/map_checker.c \
    ./proyects/render.c \
    ./proyects/move.c \
    ./proyects/error.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS) 


$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re