#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ncornacc <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:08:59 by ncornacc      #+#    #+#                  #
#    Updated: 2023/02/22 20:34:19 by ncornacc      ########   odam.nl          #
#                                                                              #
#******************************************************************************#
#############################VARIABLES################################

NAME	:=	push_swap

HEAD	:= -I./includes/ -I./libft/include

LIBFT_D	:=	./libft

LIBFT	:=	${LIBFT_D}/libft.a

CC		:=	gcc

FLAGS	:=	-Wall -Werror -Wextra

RM		:=	rm	-rf

##############################################################
#############################SOURCES##########################

OBJ_DIR	:=	obj/
SRC_DIR	:=	src/

FILE	:=	error main radix sort_op sort_op2 stack_op stack_op2

SRC		:=	${addprefix ${SRC_DIR}, ${addsuffix .c, ${FILE}}}
OBJ		:=	${addprefix ${OBJ_DIR}, ${addsuffix .o, ${FILE}}}

##############################################################
#############################COLORS###########################

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

##############################################################
#############################RULES############################

all:	${NAME}

${NAME}: ${LIBFT} ${OBJ}
	@${CC} ${CFLAG} ${OBJ} ${LIBFT} ${HEAD} -o ${NAME}
	@echo "${GREEN} push_swap compiled!${DEF_COLOR}"

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@mkdir -p ${OBJ_DIR}
	@echo	"${YELLOW} Compiling: $^ ${DEF_COLOR}"
	@${CC} ${FLAGS} ${HEAD} -c $< -o $@

${LIBFT}:
	@make -C ${LIBFT_D}

clean:
	@make clean -C ${LIBFT_D}
	${RM} ${OBJ_DIR} ${OBJ}
	@echo "${MAGENTA} Object files cleaned!${DEF_COLOR}"

fclean: clean
	@make	fclean -C ${LIBFT_D}
	${RM}	${NAME} libft.a
	@echo  "${MAGENTA} executable/archive files cleaned!${DEF_COLOR}"

re:	fclean all
	@echo	"${GREEN} Cleaned and rebuild everything for Push_Swap!${DEF_COLOR}:"

.PHONY:	re all fclean clean

##############################################################