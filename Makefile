# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 10:48:22 by tzanchi           #+#    #+#              #
#    Updated: 2023/08/10 13:19:53 by tzanchi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Compiler targets and libraries
CC			=	cc
UNAME		=	$(shell uname)
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
NAME		=	fdf
LIBFT		=	libft.a
MLX42		=	libmlx42.a

# Directories
SRCS_DIR	=	./sources/
HEAD_DIR	=	./includes/
LIBFT_DIR	=	./libft/
MLX42_DIR	=	./MLX42/
OBJ_DIR		=	${SRCS_DIR}.o

# Colours, symbols and utils
GREEN		=	\033[1;32m
CYAN		=	\033[1;36m
YELLOW		=	\033[1;33m
RED			=	\033[1;31m
NC			=	\033[0m
BOLD		=	\033[1m
TICK		=	✓

ifeq (${UNAME}, Linux)
MLX42_INCL	=	${MLX42} -I${MLX42_DIR}include -ldl -lglfw -pthread -lm
endif
ifeq (${UNAME}, Darwin)
MLX42_INCL		=	${MLX42} -I${MLX42_DIR}include -lglfw -framework Cocoa -framework OpenGL -framework IOKit
endif
ifeq (${UNAME}, Mysys)
MLX42_INCL		=	${MLX42} -I${MLX42_DIR}include -lglfw3 -lopengl32 -lgdi32
endif

SRC			=	_utils_list_1.c \
				_utils_list_2.c \
				bresenham_line_algo.c \
				errors.c \
				file_parsing.c \
				free.c \
				main.c \
				mlx_hooks.c \
				projection.c \
				visualize_map.c

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})
SRC_NR		=	$(words ${SRCS})

OBJS		=	$(addprefix ${OBJ_DIR}/, $(notdir $(SRCS:.c=.o)))

all:			project_logo ${OBJ_DIR}
				@make -s ${LIBFT}
				@make -s ${MLX42}
				@make -s ${NAME}

${LIBFT}:
				@echo "${CYAN}\nCOMPILING $$(echo ${LIBFT} | tr '[:lower:]' '[:upper:]')${NC}"
				@if [ -d ${LIBFT_DIR} ]; \
				then git -C ${LIBFT_DIR} pull; \
				else git clone git@github.com:theozanchi/42_Berlin_libft.git ${LIBFT_DIR}; \
				fi
				make -C ${LIBFT_DIR}
				@echo "${YELLOW}Moving ${LIBFT} at the root of the repository${NC}"
				@mv ${LIBFT_DIR}/${LIBFT} .

${MLX42}:
				@echo "${CYAN}\nCOMPILING $$(echo ${MLX42} | tr '[:lower:]' '[:upper:]')${NC}"
				@if [ -d ${MLX42_DIR} ]; \
				then git -C ${MLX42_DIR} pull; \
				else git clone git@github.com:codam-coding-college/MLX42.git ${MLX42_DIR}; \
				fi
				cd ${MLX42_DIR} && \
				cmake -B build && \
				cmake --build build -j4
				@echo "${YELLOW}Moving ${MLX42} at the root of the repository${NC}"
				@mv ${MLX42_DIR}build/${MLX42} .

${NAME}:		entry_message ${OBJS}
				@${CC} ${CFLAGS} ${SRCS} -I${HEAD_DIR} ${MLX42_INCL} ${LIBFT} -o ${NAME}
				@echo "${YELLOW}\nCompilation complete, ${NAME} executable at the root of the directory${NC}\n"

${OBJ_DIR}:
				@if [ ! -d "${OBJ_DIR}" ]; \
				then mkdir -p "${OBJ_DIR}"; \
				fi

$(OBJ_DIR)/%.o:	$(SRCS_DIR)%.c
				@echo -n "Compiling $(notdir $<)"; \
				${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@; \
				echo "${GREEN} ${TICK}${NC}"; 

clean:
				@make -sC ${LIBFT_DIR} clean >/dev/null 2>&1
				@if [ ! -d "${OBJ_DIR}" ]; \
				then \
					echo "Repo already clean"; \
				else \
					echo "Removing all .o files"; \
					rm -r ${OBJ_DIR}; \
				fi

fclean:			clean
				@make -sC ${LIBFT_DIR} fclean >/dev/null 2>&1
				@echo "Removing ${NAME} ${LIBFT} and ${MLX42} files from root"
				@rm -f ${NAME} ${LIBFT} ${MLX42}

re:				fclean all

project_logo:
				@echo "${RED}   _     _     _  \n  / \   / \   / \ \n ( ${CYAN}F${RED} ) ( ${CYAN}D${RED} ) ( ${CYAN}F${RED} )\n  \_/   \_/   \_/ \n\n   ${NC}a 42 project by Théo Zanchi"

entry_message:
				@echo "${CYAN}\nCOMPILING $$(echo ${NAME} | tr '[:lower:]' '[:upper:]')\n${NC}${BOLD}Compiling necessary .o files out of ${SRC_NR} .c files in total${NC}"

.PHONY:			all clean fclean re project_logo entry_message
