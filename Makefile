# NAME
NAME = fdf

# DIRECTORIES
LIBFT = include/libft/libft.a
LIBFT_PATH = include/libft/
MLX_PATH = include/minilibx-linux/
MLX_NAME = $(MLX_PATH)libmlx.a
INC = ./include/
SRC_DIR = src/
OBJS_DIR = obj/

# COMPILER & FLAGS
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
INCFLAGS += -I$(INC) -I$(LIBFT_PATH)/include -I$(MLX_PATH)
MLXFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
RM = rm -f

# SOURCES FILES 
SRC = $(SRC_DIR)main.c \
		$(SRC_DIR)parsing/init.c \
		$(SRC_DIR)parsing/parsing.c \
		$(SRC_DIR)parsing/map_info.c \
		$(SRC_DIR)parsing/cleanup.c \
		$(SRC_DIR)render/points.c \
		$(SRC_DIR)render/draw.c \
		$(SRC_DIR)render/hooks.c \
		$(SRC_DIR)render/render.c \

# CONNECT ALL SOURCES 

OBJS = $(SRC:$(SRC_DIR)%.c=$(OBJS_DIR)%.o)

# RULES

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX_NAME):
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS) $(LIBFT) $(MLX_NAME)
		@$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJS_DIR)
	@make clean -sC $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean 
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all 

.PHONY : all clean fclean re