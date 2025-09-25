# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmota-ma <rmota-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/21 15:04:39 by rmota-ma          #+#    #+#              #
#    Updated: 2025/09/16 17:22:55 by rmota-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name and compiler

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

# Sources and objects

LIBFT = includes/libft/libft.a

SRCS = main.c init.c parsing.c map_parse.c file_parse.c utils.c cleanup.c

GNL = get_next_line.c get_next_line_utils.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

GNL_OBJS = $(addprefix $(OBJS_DIR)/, $(GNL:.c=.o))

MLX = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz

SRCS_DIR = srcs

GNL_DIR = gnl

OBJS_DIR = objs

MLX_DIR = ./minilibx-linux


# Colors

NO_COLOR = \033[0m

COLOR_RED = \033[1;31m

COLOR_GREEN = \033[1;32m

COLOR_PURPLE = \033[1;35m

COLOR_CYAN = \033[1;36m

# Messages

COMP_START = @echo "$(NO_COLOR)\nCompilation starting ...\n"

CUB3D_OK = @echo "$(NO_COLOR)Cub3D status: $(COLOR_GREEN)[OK]$(NO_COLOR)\n"

CUB3D_KO = @echo "$(NO_COLOR)Cub3D status: $(COLOR_RED)[KO]$(NO_COLOR)\n"

CLEAN_RUN = @echo "$(NO_COLOR)\nCleaning objects ...\n"

FCLEAN_RUN = @echo "$(NO_COLOR)\nCleaning objects and executables ...\n"

CLEAN_DONE = @echo "$(COLOR_GREEN)Clean complete!$(NO_COLOR)\n"

# Rules

all: $(NAME)
	
$(NAME): $(OBJS) $(GNL_OBJS) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@$(CUB3D_OK)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/$(GNL_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@$(COMP_START)
	@make -C includes/libft -s

clean:
	@$(MAKE) clean -C $(MLX_DIR)
	@make clean -C includes/libft -s
	@rm -rf $(OBJS_DIR)
	@$(CLEAN_RUN)
	@$(CLEAN_DONE)
	@$(CUB3D_KO)
	
fclean: clean
	@make fclean -C includes/libft -s
	@rm -f $(NAME)
	@$(FCLEAN_RUN)
	@$(CLEAN_DONE)
	@$(CUB3D_KO)

re: fclean all

.PHONY: all clean fclean re
