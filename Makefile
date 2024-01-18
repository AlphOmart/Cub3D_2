# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edboutil <edboutil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 17:32:42 by edboutil          #+#    #+#              #
#    Updated: 2024/01/17 17:58:15 by edboutil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VAR ---------------------------------------------------------------
OBJS_DIR		=	.objs/
SRCS			=	main.c \
					srcs/mlx_init.c srcs/utils.c
OBJS			=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEP				=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))

NAME			=	cub3d
CC				=	cc
FLAGS			=	-Wall -Wextra -Werror -MMD -MP
RF				=	rm -rf
MLX_NAME		=	libmlx.a

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
MLX_DIR			=	./mlx/linux/
MLX_FLAGS		=	-lXext -lX11 -lz
endif

ifeq ($(UNAME), Darwin)
MLX_DIR			=	./mlx/mac/
MLX_FLAGS		=	-framework OpenGL -framework AppKit
endif

# RULES -------------------------------------------------------------
all:				mlx $(NAME)

$(NAME):			$(OBJS)
					$(CC) $(FLAGS) $(OBJS) $(MLX_DIR)$(MLX_NAME) $(MLX_FLAGS) -lm -o $(NAME)

-include $(DEP)
$(OBJS_DIR)%.o:		%.c
					@mkdir -p $(OBJS_DIR)
					@mkdir -p $(OBJS_DIR)srcs
					$(CC) $(FLAGS) -c $< -o $@

mlx:
					make -C $(MLX_DIR)

clean:
					$(RF) $(OBJS_DIR)
					make clean -C $(MLX_DIR)

fclean:				clean
					$(RF) $(NAME)

re:					fclean all

.PHONY:				all mlx clean fclean re run


