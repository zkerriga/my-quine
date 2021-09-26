# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerriga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/26 10:24:30 by zkerriga          #+#    #+#              #
#    Updated: 2021/09/26 10:24:31 by zkerriga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all
all:
	@echo "Choose project: Colleen, Grace, or Sully"
	@echo "And write command: \`make <project-name>\`"

.PHONY: clean
clean:
	@$(MAKE) -C $(COLLEEN_DIR) clean --no-print-directory --silent

.PHONY: re
re: clean Colleen

### Colleen part

COLLEEN_DIR = ./Colleen
COLLEEN_TARGET = $(COLLEEN_DIR)/Colleen

.PHONY: Colleen
Colleen: $(COLLEEN_TARGET)

$(COLLEEN_TARGET):
	@$(MAKE) -C $(COLLEEN_DIR) --no-print-directory --silent

### End of Colleen part

