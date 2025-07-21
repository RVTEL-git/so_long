# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 16:32:33 by barmarti          #+#    #+#              #
#    Updated: 2025/07/21 13:58:37 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror -g


SRC_DIRS := . handle_input init_data manage_error map_init map_init/flood_fill
OBJ_DIR := obj
INCLUDES := -Iinclude -Iinclude/libft -Iinclude/libft/ft_printf -Iinclude/libft/ft_printf/src -Iinclude/libft/ft_printf/conversions

MLX_DIR := include/minilibx-linux
MLX_LIB := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR := include/libft
LIBFT := $(LIBFT_DIR)/libft.a


SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))


all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
