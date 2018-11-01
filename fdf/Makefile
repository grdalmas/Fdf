# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grdalmas <grdalmas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 13:09:11 by grdalmas          #+#    #+#              #
#    Updated: 2018/04/25 13:43:41 by grdalmas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf	

CC = gcc
FLAGS = -Wall -Wextra -Werror
FRAM = -L minilibx -I minilibx -lmlx -framework OpenGL -framework Appkit

OBJ_PATH = ./obj/
LIBFT_PATH = ./libft/
INC_PATH = ./includes/
SRC_PATH = ./src/

SRC_NAME =	fdf_main.c \
			fdf_color_info.c \
			fdf_key_inputs.c \
			fdf_init.c \
			fdf_modif_n_move.c \
			fdf_parse_struc.c \
			fdf_print_funct.c \
			fdf_print.c \
			fdf_z_manipulations.c
			
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fdf.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
			@make -C $(LIBFT_PATH)
			$(CC) -o $(NAME) $(FRAM) -L $(LIBFT_PATH) -lft $^ -o $@
			@echo "It's done, fdf is ready"
			
$(OBJ_PATH)%.o :$(SRC_PATH)%.c
				mkdir -p $(OBJ_PATH)
				$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
		@make -C $(LIBFT_PATH) clean
		@rm -rf $(OBJ_PATH)
		@echo "Objects removed"

fclean: clean
		@make -C $(LIBFT_PATH) fclean
		@rm -rf $(NAME)
		@echo "All clean"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
