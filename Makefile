# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 17:53:36 by rvandepu          #+#    #+#              #
#    Updated: 2024/01/05 16:52:04 by rvandepu         ###   ########.fr        #
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
LIB_PATH = $(LIB_DIR)/$(LIB)

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

$(TEST_BIN): CFLAGS := -Wall -Wextra -g
$(TEST_BIN): LDFLAGS := -L.
$(TEST_BIN): LDLIBS := -lftprintf

$(LIB_PATH):
	$(MAKE) -C $(LIB_DIR) $(LIB)

$(NAME): $(LIB_PATH) $(OBJ)
	$(AR) rcs $@ $(OBJ)
	printf "OPEN $@\nADDLIB $(LIB_PATH)\nSAVE\nEND" | $(AR) -M
