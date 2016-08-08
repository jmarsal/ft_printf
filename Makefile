# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/08/08 18:12:02 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftprintf
CC = gcc
OPTI = -O1
CFLAGS_DEBUG = -g3 -O0 -fsanitize=address
CFLAGS = -Wall -Werror -Wextra -pedantic $(OPTI)
SRC_DIR = ./test/
SRC_FILES = test1.c
OBJ_PATH = ./obj
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_PATH)/%.o)
# INC_PATH = -I./libft/ -I./libftprintf/ -I./includes/
# LIB_PATH = -L./libftprintf/ -lftprintf -L./libft/ -lft

all: $(NAME)
$(NAME): $(OBJ_FILES)
	# @make -C libft
	# @make -C libmlx
	@$(CC) -o $(NAME) $(OBJ_FILES) $(CFLAGS) $(INC_PATH) $(LIB_PATH)
	@echo "\n-----------------------------------------"
	@echo "|\033[32;1m\t$(NAME) has been created !\t\t\033[0m|"
	@echo "-----------------------------------------\n"

$(OBJ_PATH)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -o $@ -c $< $(CFLAGS) $(INC_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall $(NAME) files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n---------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t\t|"
	@echo "---------------------------------\n"

re: fclean all

libs:
	@make -C libft
	@make -C libftprintf

libs-clean:
	@make -C libft clean
	@make -C libftprintf clean

libs-fclean:
	@make -C libft fclean
	@make -C libftprintf clean

libs-re: libs-fclean
	@make -C libft re
	@make -C libftprintf re

fclean-all: fclean libs-fclean

debug: CFLAGS := $(filter-out $(OPTI),$(CFLAGS) $(CFLAGS_DEBUG))
debug: re
	@echo "\n-----------------------------------------------------------------"
	@echo "|\033[32;1m\tDebug mode for $(NAME) with $(CFLAGS_DEBUG)!\t\033[0m|"
	@echo "-----------------------------------------------------------------\n"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re, libs, libs-clean, libs-fclean, libs-re \
		fclean-all, debug, norme
