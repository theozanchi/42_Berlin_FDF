# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:48:22 by tzanchi           #+#    #+#              #
#    Updated: 2023/07/24 18:54:47 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
NAME		=	fdf
LIBFT		=	libft.a
MLX42		=	libmlx42.a

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/
MLX42_DIR	=	./MLX42/

SRC			=	errors.c \
				file_parsing.c \
				free.c \
				main.c \
				projection.c \
				utils_list.c \
				utils_matrix_calc.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

all:			
				make ${LIBFT}
				make ${MLX42}
				make ${NAME}

${LIBFT}:
				@if [ -d ${LIBFT_DIR} ]; \
				then git -C ${LIBFT_DIR} pull; \
				else git clone git@github.com:theozanchi/42_Berlin_libft.git ${LIBFT_DIR}; \
				fi
				make -C ${LIBFT_DIR}
				mv ${LIBFT_DIR}/${LIBFT} .

${MLX42}:
				@if [ -d ${MLX42_DIR} ]; \
				then git -C ${MLX42_DIR} pull; \
				else git clone git@github.com:codam-coding-college/MLX42.git ${MLX42_DIR}; \
				fi
				cd ${MLX42_DIR} && \
				cmake -B build && \
				cmake --build build -j4
				mv ${MLX42_DIR}build/${MLX42} .

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${SRCS} -I${HEAD_DIR} ${LIBFT} -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@
				
clean:
				make -C ${LIBFT_DIR} clean
				rm -f ${OBJS}

fclean:			clean
				make -C ${LIBFT_DIR} fclean
				rm -f ${NAME} ${LIBFT} ${MLX42}

re:				fclean all

.PHONY:			all clean fclean re
