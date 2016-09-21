# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/09/20 00:16:23 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS_DEBUG = -g -O0
OPTI = -O2
CFLAGS = -Wall -Werror -Wextra -pedantic $(OPTI)

# Headers
INC_PATH = includes
INC_FILES = ft_printf.h
HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH))

# Sources
SRC_PATH = srcs
vpath %.c $(SRC_PATH)
SOURCES += ft_printf.c \
						parser.c \
						output.c \
						init.c \
						init_f_conv.c \
						conv_hex_bin.c \
						conv_str.c \
						conv_char.c \
						conv_decimal.c \
						conv_mem.c \
						conv_octal.c \
						parser_helper.c \
						output_f_caracters.c \
						get_content_format.c \
						get_content_helper.c \
						error.c \
						output_char.c \
						output_str.c \
						output_decimal.c \
						output_hex_bin.c \
						output_mem.c \
						output_octal.c \
						modifier.c

# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))

# Libft
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CFLAGS += -I $(LIBFT_PATH)/includes

# Rules
all: $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS) $(LIBFT)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n-------------------------------------------------"
	@echo "|\033[32;1m\t$(NAME) has been created !\t\033[0m|"
	@echo "-------------------------------------------------\n"

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)
$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	@-mkdir -p $@

clean:
	@make clean -C libft/
	@rm -rf $(OBJ_PATH)
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31mall files.o are deleted\033[0m\t\t|"
	@echo "-----------------------------------------\n"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t|"
	@echo "-----------------------------------------\n"

re: fclean all

debug: CFLAGS := $(filter-out $(OPTI),$(CFLAGS) $(CFLAGS_DEBUG))
debug : re
	@echo "\n-----------------------------------------------------------------"
	@echo "|\033[32;1m\tDebug mode for $(NAME) with $(CFLAGS_DEBUG)!\t\033[0m|"
	@echo "-----------------------------------------------------------------\n"

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re, libs, libs-clean, libs-fclean, libs-re \
		fclean-all, debug, norme
