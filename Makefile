# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2023/12/19 17:53:47 by rvandepu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

FILES  := ft_print \
#FILES  := ft_printf \
#		  ft_print \

TEST_BIN := tester

OBJ := $(FILES:%=%.o)

LIB_DIR := libft
LIB		:= libft.a

CPPFLAGS += -I$(LIB_DIR)
CFLAGS   += -Wall -Wextra -Werror
LDFLAGS  += -L$(LIB_DIR)
LDLIBS   += -lft

.PHONY: all clean fclean re bonus test

all: $(NAME)

clean:
	$(RM) $(OBJ) $(TEST_BIN)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

test: re $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): CFLAGS := -g
$(TEST_BIN): LDFLAGS := -L.
$(TEST_BIN): LDLIBS := -lftprintf

$(LIB):
	$(MAKE) -C $(LIB_DIR) $@

$(NAME): $(LIB) $(OBJ)
	$(AR) rcs $@ $(OBJ)
	echo "OPEN $@\nADDLIB $(LIB_DIR)/$(LIB)\nSAVE\nEND" | $(AR) -M
