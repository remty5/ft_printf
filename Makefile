# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2023/11/13 17:45:42 by rvandepu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRC  := test.c \

OBJ := $(SRC:%.c=%.o)

LIB_PATH := libft
LIB		 := libft.a

CPPFLAGS += -I$(LIB_PATH)
CFLAGS   += -Wall -Wextra -Werror
LDFLAGS  += -static -L$(LIB_PATH)
LDLIBS   += -lft

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

$(LIB):
	$(MAKE) -C $(LIB_PATH) $@

$(NAME): $(LIB) $(OBJ)
	$(AR) rcs $@ $(OBJ)
	echo "OPEN $@\nADDLIB $(LIB_PATH)/$(LIB)\nSAVE\nEND" | $(AR) -M
