# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azakizad <azakizad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 23:09:36 by azakizad          #+#    #+#              #
#    Updated: 2022/06/24 08:19:12 by azakizad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Disable built-in rules and variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

# Compiler Variables
CC		= cc
CFLAGSS	= -Wall -Wextra -Werror
INCFLAG	= -I.
AR		= ar
ARFLAGS = -rcs
# File Variables
NAME	= libft.a
MAIN	= atoi bzero calloc strlen itoa strdup strchr strrchr\
		isalpha isdigit isalnum isascii isprint memset memcpy\
		memmove strlcpy strlcat toupper tolower strncmp memchr\
		memcmp strnstr atoi substr strjoin split strmapi\
		strtrim striteri putchar_fd putstr_fd putendl_fd putnbr_fd
BONUS	= lstnew lstadd_front lstsize lstlast lstadd_back\
		lstdelone lstclear lstiter lstmap
MAINFILES	= $(addprefix ft_,$(addsuffix .c, $(MAIN)))
BONUSFILES	= $(addprefix ft_,$(addsuffix .c, $(BONUS)))
MAINOBJ	= $(MAINFILES:.c=.o)
BONUSOBJ = $(BONUSFILES:.c=.o)

all:	$(NAME) bonus

$(NAME): $(MAINOBJ)
	$(AR) $(ARFLAGS) $@ $^

bonus:	$(BONUSOBJ)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

clean:
	rm -f $(MAINOBJ) $(BONUSOBJ)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: bonus clean fclean re all
