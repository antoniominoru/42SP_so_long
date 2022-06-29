# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 19:09:53 by aminoru-          #+#    #+#              #
#    Updated: 2022/06/01 20:36:17 by aminoru-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT = ./libft/libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
INCS	= -I ./include -I ./libft
SRCS	=	./src/ft_appendchr.c \
			./src/ft_convertions_utils.c \
			./src/ft_convert_s.c \
			./src/ft_fs_sub_specifier.c \
			./src/ft_printf.c \
			./src/ft_uitoa.c \
			./src/ft_convert_c.c \
			./src/ft_convert_p.c \
			./src/ft_convert_ux.c \
			./src/ft_inicialize.c \
			./src/ft_strndup.c \
			./src/ft_convert_d_i.c \
			./src/ft_convert_pct.c \
			./src/ft_format_specifiers.c \
			./src/ft_placeholder.c \
			./src/ft_type_specifier.c

OBJS	=	${SRCS:.c=.o}

all: 		${NAME}

${NAME}: 	${OBJS} $(LIBFT)
				ar -rcs ${NAME} ${OBJS}
				ranlib ${NAME}

bonus:	all 

.c.o:
				${CC} ${CFLAGS} $(INCS) -c $< -o ${<:.c=.o}

$(LIBFT):
				make -C ./libft
				cp $(LIBFT) $(NAME)

clean:
				make clean -C ./libft
				rm -f ${OBJS} ${OBJS_BONUS}

fclean: 	clean
				make fclean -C ./libft
				rm -f ${NAME}

re: 		fclean all

rebonus:	fclean bonus

.PHONY: all clean fclean re bonus rebonus