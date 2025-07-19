# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barmarti <barmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/05 16:32:33 by barmarti          #+#    #+#              #
#    Updated: 2025/07/19 19:31:01 by barmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
RM          = rm -f
MKDIR       = mkdir -p

# ----------------------------------------------------------------------------- #
# Dossiers
# ----------------------------------------------------------------------------- #

SRC_DIRS    = . map_init map_init/flood_fill manage_error init_data handle_input
OBJ_DIR     = obj
LIBFT_DIR   = include/libft
MLX_DIR     = include/minilibx-linux

INCLUDE_DIRS = include $(LIBFT_DIR) $(LIBFT_DIR)/ft_printf $(LIBFT_DIR)/ft_printf/src $(LIBFT_DIR)/ft_printf/conversions
INCLUDES    = $(addprefix -I, $(INCLUDE_DIRS))

LIBFT       = $(LIBFT_DIR)/libft.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ----------------------------------------------------------------------------- #
# Fichiers sources
# ----------------------------------------------------------------------------- #

SRC         = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJ         = $(SRC:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                  REGLES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) $(LIBFT) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c | $(INC)
	@$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# **************************************************************************** #
#                                 LIBFT                                         #
# **************************************************************************** #

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# **************************************************************************** #
#                                CLEANING                                       #
# **************************************************************************** #

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
