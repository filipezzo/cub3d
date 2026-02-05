# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 10:52:32 by fsousa            #+#    #+#              #
#    Updated: 2026/02/05 18:02:35 by fsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3d

SRC_DIR			= src
OBJ_DIR			= obj
BIN_DIR			= bin
LIBS_DIR			= libs
INCLUDE_DIR = include
ENGINE_DIR = $(SRC_DIR)/engine
MLX_DIR = libs/mlx


EXEC = $(BIN_DIR)/$(NAME)

LIBFT = $(LIBS_DIR)/libft/libft.a
MLX_A = $(MLX_DIR)/libmlx.a

SRC_FILES = main.c
ENGINE_FILES = mock_world.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))	\
		$(addprefix $(ENGINE_DIR)/, $(ENGINE_FILES))

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