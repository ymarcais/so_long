# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 11:38:49 by ymarcais          #+#    #+#              #
#    Updated: 2023/03/12 12:37:36 by ymarcais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# /* ~~~~~~ SOURCES ~~~~~~ */
SRCS_DIR = ./srcs/
SRCS = ./srcs/00_Init_Parsing/create_map.c \
	./srcs/00_Init_Parsing/init_map.c \
	./srcs/00_Init_Parsing/init_players.c \
	./srcs/01_Errors/check_ber.c \
	./srcs/01_Errors/check_map.c \
	./srcs/01_Errors/check_path.c \
	./srcs/01_Errors/error_msg.c \
	./srcs/02_Graphics/render.c \
	./srcs/02_Graphics/mlx_utils.c \
	./srcs/02_Graphics/generate_anim.c \
	./srcs/03_Events/handlers.c \
	./srcs/03_Events/moves.c \
	./srcs/03_Events/enemy_moves.c \
	./srcs/03_Events/move_msg.c \
	./srcs/main.c \
	./get_next_line/get_next_line.c \
	./get_next_line/get_next_line_utils.c

OBJS = ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

# /* ~~~~~~~ INCLUDING GNL ~~~~~~~ */
GNL_DIR = ./get_next_line/
GNL = get_next_line.c \
	get_next_line_utils.c \

GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}

# /* ~~~~~~~ INCLUDING LIBFT ~~~~~~~ */
LIBFT_DIR = ./libft/
LIBFT_MAKE = Makefile
LIBFT_PATH = ${LIBFT_DIR}/libft.a

# /* ~~~~~~~ INCLUDING MINILIBX ~~~~~~~ */
MLX_DIR = mlx_linux
MLX_MAKE = Makefile
MLX_PATH = ${MLX_DIR}/libmlx.a

# /* ~~~~~~~ COMPILING INFO ~~~~~~~ */
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fPIE
MFLAGS = -ldl -lmlx -L${MLX_DIR} -lm -lXext -lX11 -Imlx $(MLX_PATH) -pie
IFLAGS:= -I ./includes
LFLAGS:= -L $(LIBFT_DIR) -lft 

# /* ~~~~~~~ OTHER ~~~~~~~ */
NAME = so_long
RM = rm -f


# /* ~~~~~~~ Colors ~~~~~~~ */
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

all:	${NAME}		

$(NAME): 
		@make -C ${MLX_DIR}
		@make -C $(LIBFT_DIR)
		@$(CC) -I ./libft -I ./get_next_line $(CFLAGS) ${SRCS} -o $(NAME) ${LFLAGS} ${MFLAGS}

clean:
		@echo $(PURPLE) "[🧹Cleaning...🧹]" $(EOC)
		@${RM} ${OBJS}
		@${RM} -r ${OBJ_DIR} 
		@make -C ${LIBFT_DIR} -f ${LIBFT_MAKE} clean

fclean: clean
		@echo $(PURPLE) "[🧹FCleaning...🧹]" $(EOC)
		@${RM} ${OBJS} ${NAME}
		
re: 	fclean all

.PHONY: all clean fclean re
