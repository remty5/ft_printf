# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2023/12/21 21:24:12 by rvandepu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

FILES  := ft_printf \
		  ft_parser \
		  ft_string \
		  ft_putnbr \
		  ft_numbers \

TEST_BIN := tester

OBJ := $(FILES:%=%.o)

LIB_DIR := libft
LIB		:= libft.a

CPPFLAGS += -I$(LIB_DIR)
CFLAGS   += -Wall -Wextra -Werror
#LDFLAGS  += -L$(LIB_DIR)
#LDLIBS   += -lft

.PHONY: all clean fclean re bonus test

all: $(NAME)

clean:
	$(RM) $(OBJ) $(TEST_BIN)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

test: CFLAGS += -g
test: re $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): LDFLAGS := -L.
$(TEST_BIN): LDLIBS := -lftprintf

$(LIB):
	$(MAKE) -C $(LIB_DIR) $@

$(NAME): $(LIB) $(OBJ)
	$(AR) rcs $@ $(OBJ)
	printf "OPEN $@\nADDLIB $(LIB_DIR)/$(LIB)\nSAVE\nEND" | $(AR) -M
