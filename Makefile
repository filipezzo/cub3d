# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 10:52:32 by fsousa            #+#    #+#              #
#    Updated: 2026/02/20 01:50:43 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d

SRC_DIR			= src
OBJ_DIR			= obj
BIN_DIR			= bin
LIBS_DIR			= libs
INCLUDE_DIR = include
ENGINE_DIR = $(SRC_DIR)/engine
MOCK_DIR = $(SRC_DIR)/mock
RENDER_DIR = $(SRC_DIR)/render
PLAYER_DIR = $(SRC_DIR)/player
PARSER_DIR = $(SRC_DIR)/parser
UTIL_DIR = $(SRC_DIR)/util
MLX_DIR = libs/mlx

EXEC = $(BIN_DIR)/$(NAME)

LIBFT = $(LIBS_DIR)/libft/libft.a
MLX_A = $(MLX_DIR)/libmlx.a

SRC_FILES = main.c
ENGINE_FILES = engine_init.c engine_tick.c engine_shutdown.c engine_register_hooks.c engine_events.c
MOCK_FILES = mock_world.c
RENDER_FILES = pixel.c draw.c minimap.c
PLAYER_FILES = player_update.c
PARSER_FILES = analize_map.c helper_parse_map.c load_color.c load_texture.c parse.c set_vec2.c validate_fpath.c
UTIL_FILES =  destroy_cmtx_rev.c destroy.c perr.c pinfo.c safe_close_fd.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))	\
		$(addprefix $(ENGINE_DIR)/, $(ENGINE_FILES)) 	\
		$(addprefix $(MOCK_DIR)/, $(MOCK_FILES))	\
		$(addprefix $(RENDER_DIR)/, $(RENDER_FILES))	\
		$(addprefix $(PLAYER_DIR)/, $(PLAYER_FILES))	\
		$(addprefix $(PARSER_DIR)/, $(PARSER_FILES))	\
		$(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER = $(INCLUDE_DIR)/cub3d.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
IFLAGS = -I $(INCLUDE_DIR)
LDFLAGS  = -L $(LIBS_DIR)/libft -L $(MLX_DIR)
LDLIBS   = -lft -lmlx -lXext -lX11 -lm -lz

RM = rm -rf

all: $(EXEC)

$(EXEC): $(LIBFT) $(MLX_A) $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(EXEC) $(LDFLAGS) $(LDLIBS)
	@echo "[\033[0;32mOK\033[0m] $(NAME) compiled in $(BIN_DIR) 👌👌😍"

$(MLX_A):
	@make -C $(MLX_DIR)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "[\033[0;32mOK\033[0m] Compiled: $< ✅"

$(LIBFT):
	@make -C $(LIBS_DIR)/libft


clean:
	@$(RM) $(OBJ_DIR)
	@echo "[\033[0;31mOK\033[0m] Cleaned object files."

fclean: clean
	@$(RM) $(BIN_DIR)
	@$(RM) $(SLIB_DIR)
	@echo "[\033[0;31mOK\033[0m] Complete cleaning."

re: fclean all

.PHONY: all clean fclean re 