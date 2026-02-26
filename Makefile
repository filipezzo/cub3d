# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhidani <mhidani@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 10:52:32 by fsousa            #+#    #+#              #
#    Updated: 2026/02/26 13:25:09 by mhidani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d

SRC_DIR			= src
OBJ_DIR			= obj
LIBS_DIR		= libs
INCLUDE_DIR		= include
ENGINE_DIR		= $(SRC_DIR)/engine
MOCK_DIR		= $(SRC_DIR)/mock
RENDER_DIR		= $(SRC_DIR)/render
TEXTURES_DIR	= $(SRC_DIR)/textures
PLAYER_DIR		= $(SRC_DIR)/player
RAYCAST_DIR		= $(SRC_DIR)/raycast
PARSER_DIR		= $(SRC_DIR)/parser
UTIL_DIR		= $(SRC_DIR)/util
LIBFT_DIR		= $(LIBS_DIR)/libft
MLX_DIR			= $(LIBS_DIR)/mlx
CLEAN_DIR		= $(SRC_DIR)/clean

EXEC			= $(NAME)

LIBFT			= $(LIBFT_DIR)/libft.a
MLX_A			= $(MLX_DIR)/libmlx.a

SRC_FILES		= main.c
ENGINE_FILES	= engine_init.c engine_tick.c engine_shutdown.c \
				  engine_register_hooks.c engine_events.c
MOCK_FILES		= mock_world.c
RENDER_FILES	= pixel.c render_draw.c minimap.c render_frame.c \
				  render_minimap.c
PLAYER_FILES	= player_update.c player_update_utils.c
RAYCAST_FILES	= raycast.c ray_dda.c ray_draw.c ray_init.c ray_project.c
TEXTURES_FILES	= textures.c textures_utils.c
PARSER_FILES	= analize_map.c helper_parse_map.c load_color.c load_texture.c \
				  parse.c dupmap.c set_vec2.c validate_fpath.c
CLEAN_FILES		= game_shutdown.c
UTIL_FILES		= destroy_cmtx_rev.c perr.c pinfo.c safe_close_fd.c

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
				  $(addprefix $(ENGINE_DIR)/, $(ENGINE_FILES)) \
				  $(addprefix $(MOCK_DIR)/, $(MOCK_FILES)) \
				  $(addprefix $(RENDER_DIR)/, $(RENDER_FILES)) \
				  $(addprefix $(PLAYER_DIR)/, $(PLAYER_FILES)) \
				  $(addprefix $(RAYCAST_DIR)/, $(RAYCAST_FILES)) \
				  $(addprefix $(TEXTURES_DIR)/, $(TEXTURES_FILES)) \
				  $(addprefix $(PARSER_DIR)/, $(PARSER_FILES)) \
				  $(addprefix $(CLEAN_DIR)/, $(CLEAN_FILES)) \
				  $(addprefix $(UTIL_DIR)/, $(UTIL_FILES))

OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADER			= $(INCLUDE_DIR)/cub3d.h

CC				= cc
CFLAGS			= -g -Wall -Wextra -Werror -MMD -MP
IFLAGS			= -I $(INCLUDE_DIR)
LDFLAGS			= -L $(LIBS_DIR)/libft -L $(MLX_DIR)
LDLIBS			= -lft -lmlx -lXext -lX11 -lm -lz

RM				= rm -rf

all: $(EXEC)

$(EXEC): $(LIBFT) $(MLX_A) $(OBJS)
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
	@$(RM) $(LIBFT)
	@$(RM) $(MLX_A)
	@$(RM) $(SLIB_DIR)
	@echo "[\033[0;31mOK\033[0m] Complete cleaning."

re: fclean all

.PHONY: all clean fclean re
