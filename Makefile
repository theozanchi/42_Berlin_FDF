# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:48:22 by tzanchi           #+#    #+#              #
#    Updated: 2023/07/18 20:19:49 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
NAME		=	fdf
LIBFT		=	libft.a
MINILIB		=	libmlx.a

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/
MINILIB_DIR	=	./minilibx-linux/

SRC			=	errors.c \
				free.c \
				main.c \
				map_parsing.c \
				utils_list.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

all:			
				make ${LIBFT}
				make ${MINILIB}
				make ${NAME}

${LIBFT}:
				make -C ${LIBFT_DIR}
				mv ${LIBFT_DIR}/${LIBFT} .

${MINILIB}:
				make -C ${MINILIB_DIR}
				mv ${MINILIB_DIR}/${MINILIB} .

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${SRCS} -I${HEAD_DIR} ${LIBFT} -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@
				
clean:
				make -C ${LIBFT_DIR} clean
				make -C ${MINILIB_DIR} clean
				rm -f ${OBJS}

fclean:			clean
				make -C ${LIBFT_DIR} fclean
				rm -f ${NAME}
				rm -f ${LIBFT}
				rm -f ${MINILIB}

re:				fclean all

.PHONY:			all clean fclean re
