# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerriga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 14:36:13 by zkerriga          #+#    #+#              #
#    Updated: 2021/10/23 14:36:15 by zkerriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Sully

C_DIR = C
ASM_DIR = asm

CC = clang
COMPILE_FLAGS = -Wall -Wextra -Werror

FILE_NAMES = Sully
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
