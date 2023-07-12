# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:48:22 by tzanchi           #+#    #+#              #
#    Updated: 2023/07/12 10:51:38 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
NAME		=	fdf
LIBFT		=	libft.a

SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/

SRC			=	

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})

OBJS		=	${SRCS:.c=.o}

all:			
				make ${LIBFT}
				make ${NAME}

${LIBFT}:
				make -C ${LIBFT_DIR}
				mv ${LIBFT_DIR}/${LIBFT} .

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${CFLAGS} ${SRCS} -I${HEAD_DIR} ${LIBFT} -o ${NAME}

.c.o:
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@
				
clean:
				make -C ${LIBFT_DIR} clean
				rm -f ${OBJS}

fclean:			clean
				make -C ${LIBFT_DIR} fclean
				rm -f ${NAME}
				rm -f ${LIBFT}

re:				fclean all

.PHONY:			all clean fclean re
