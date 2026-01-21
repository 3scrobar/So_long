NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCDIR = source/
OBJDIR = object/
INC_DIR = includes/

SRC = so_long.c utils.c move.c init.c draw.c colision.c check.c enemy.c utils2.c
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# ---- LIBFT
LIBFT_DIR = libft/
LIBFT_A = $(LIBFT_DIR)libft.a

# ---- MLX
MLX_DIR = minilibx-linux/
MLX_A = $(MLX_DIR)libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A) $(MLX_FLAGS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
