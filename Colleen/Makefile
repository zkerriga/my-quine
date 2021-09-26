# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerriga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 10:31:01 by zkerriga          #+#    #+#              #
#    Updated: 2021/09/26 10:31:02 by zkerriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Colleen

C_DIR = C
ASM_DIR = asm

CC = clang
COMPILE_FLAGS = -Wall -Wextra -Werror

FILE_NAMES = Colleen
C_FILES = $(addprefix $(C_DIR)/, $(addsuffix .c, $(FILE_NAMES)))

.PHONY: all
all: $(NAME)
	@echo $(NAME) is assembled!

$(NAME): $(C_FILES)
	$(CC) $(COMPILE_FLAGS) $(C_FILES) -o $(NAME)

.PHONY: clean
clean:
	rm -rf $(NAME)

.PHONY: re
re: clean all
