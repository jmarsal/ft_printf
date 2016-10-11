# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/10/10 16:54:05 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS_DEBUG = -g -O0
OPTI = -O2
CFLAGS = -Wall -Werror -Wextra -pedantic $(OPTI)

# Headers
LIBFT_INC_PATH = libft/includes
LIBFT_INC_FILES = $(LIBFT_INC_PATH)/libft.h
INC_PATH = includes
INC_FILES = ft_printf.h
HEADERS = $(INC_FILES:%.h=$(INC_PATH)/%.h)
HEADERS +=  $(LIBFT_INC_FILES)
CFLAGS += $(addprefix -I,$(INC_PATH) $(LIBFT_INC_PATH))

# Sources
SRC_PATH = srcs
SRC_PATH += libft
vpath %.c $(SRC_PATH)
SOURCES = ft_printf.c \
						parser.c \
						parser_helper.c \
						init.c \
						init_f_conv.c \
						get_content_format.c \
						get_content_helper.c \
						conv_hex.c \
						conv_char_str.c \
						conv_bin_dec_oct.c \
						conv_mem.c \
						error.c \
						output.c \
						output_width_precision_minus.c \
						output_width_precision_not_minus.c \
						output_char_str.c \
						output_bin_dec_octal.c \
						output_hex.c \
						output_mem.c \
						conv_helper.c \
						nparser.c

LIBFT_SRCS = ft_putchar_fd.c \
						ft_atoi.c \
						ft_get_number.c \
						ft_isalnum.c \
						ft_itoa.c \
						ft_itoa_base.c \
						ft_litoa.c \
						ft_litoa_base.c \
						ft_memalloc.c \
						ft_memcpy.c \
						ft_strcat.c \
						ft_strchr.c \
						ft_strcmp.c \
						ft_strdup.c \
						ft_strnew.c \
						ft_strjoin.c \
						ft_strncmp.c \
						ft_strrev.c \
						ft_strtolower.c \
						ft_ulitoa.c \
						ft_ulitoa_base.c \
						ft_bzero.c\
						ft_isalpha.c \
						ft_isdigit.c \
						ft_putchar.c \
						ft_putstr.c \
						ft_strcpy.c \
						ft_strlen.c \
						ft_memset.c \
						ft_tolower.c

# Libft
 LIBFT_PATH = libft
 LIBFT = $(LIBFT_PATH)/libft.a

# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o) $(LIBFT_SRCS:%.c=%.o))

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
	@make clean -C $(LIBFT_PATH)/
	@rm -rf $(OBJ_PATH)
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31mall files.o are deleted\033[0m\t\t|"
	@echo "-----------------------------------------\n"

fclean: clean
	@make fclean -C $(LIBFT_PATH)/
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
	norminette $(SOURCES) $(LIBFT_SRCS)
	norminette $(HEADERS)*.h

.PHONY:  all, clean, fclean, re, debug, norme
