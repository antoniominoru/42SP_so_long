# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 23:11:13 by aminoru-          #+#    #+#              #
#    Updated: 2022/07/04 16:42:33 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTPRINTH = ./printf/libftprintf.a

CC = gcc
CFLAG = -Wall -Werror -Wextra
INCS = -I ./include
SRCS = ./src/get_next_line.c \
		./src/so_long.c 

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS} $(LIBFTPRINTH)
			ar -rcs ${NAME} ${OBJS}
			ranlib ${NAME}

.c.o:
			${CC} ${CFLAG} ${INCS} -c $< -o ${<:.c=.o}

$(LIBFTPRINTH):
			make -C ./printf
			cp $(LIBFTPRINTH) $(NAME)
clean:
			make clean -C ./printf
			rm -f ${OBJS}

fclean: clean
			make fclean -C ./printf
			rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
