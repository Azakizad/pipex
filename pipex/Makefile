# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 08:43:16 by azakizad          #+#    #+#              #
#    Updated: 2022/06/28 21:06:07 by azakizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS_FILES	= 	${shell find ./src -name "*.c"}

SRCS	= 	$(SRCS_FILES)
OBJCS	=	$(patsubst %.c,%.o,$(SRCS))

LIB_DIR		=	Libft
HEADER		=	-I./pipex.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -I .
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJCS) pipex.h
			@echo "\033[33m----Compiling pipex----"
			@make -C $(LIB_DIR) --silent
			@$(CC) $(CFLAGS) $(HEADER) $(LIB_DIR)/libft.a $(OBJCS) -o $(NAME)
			@#clear
			@echo "PIPE IT!!!"

%.o:		%.c libft/*.c
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJCS)
			$(RM) $(OBJS_BONUS)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
