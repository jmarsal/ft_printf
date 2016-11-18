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
LIBFT_INC_FILES = libft.h
INC_PATH = includes
INC_FILES = ft_printf.h
HEADERS =  $(LIBFT_INC_FILES:%.h=$(LIBFT_INC_PATH)/%.h)
HEADERS += $(INC_FILES:%.h=$(INC_PATH)/%.h)
CFLAGS += $(addprefix -I,$(INC_PATH) $(LIBFT_INC_PATH))

# Sources
SRC_PATH = srcs/
SRC_PATH += srcs/conversions
SRC_PATH += srcs/error
SRC_PATH += srcs/memory
SRC_PATH += srcs/lexer_parser
SRC_PATH += srcs/output
SRC_PATH += libft/src_array
SRC_PATH += libft/src_char_control
SRC_PATH += libft/src_conversion
SRC_PATH += libft/src_file_manage
SRC_PATH += libft/src_list
SRC_PATH += libft/src_math
SRC_PATH += libft/src_mem
SRC_PATH += libft/src_numeric_manage
SRC_PATH += libft/src_output
SRC_PATH += libft/src_str_control
SRC_PATH += libft/src_str_manage
SRC_PATH += libft/src_buffer
vpath %.c $(SRC_PATH)

SOURCES = ft_printf.c \
						ft_asprintf.c \
						ft_sprintf.c \
						init.c \
						init_tab_conv.c \
						tab_conv_add.c \
						lex_and_parse.c \
						parser.c \
						parser_color.c \
						parser_percent.c \
						parser_str.c \
						parser_specifier.c \
						conv_hex.c \
						conv_char_str.c \
						conv_bin_dec_oct.c \
						conv_mem.c \
						error.c \
						output.c \
						output_minus.c \
						output_without_minus.c \
						output_char_str.c \
						output_bin_dec_octal.c \
						output_hex.c \
						output_mem.c \
						output_helper.c

LIBFT_SRCS = 			ft_putchar_fd.c \
						ft_atoi.c \
						ft_get_number.c \
						ft_isalnum.c \
						ft_abs.c \
						ft_itoa_base.c \
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
						ft_utoa_base.c \
						ft_bzero.c\
						ft_isalpha.c \
						ft_isdigit.c \
						ft_putchar.c \
						ft_putstr.c \
						ft_strcpy.c \
						ft_strlen.c \
						ft_memset.c \
						ft_tolower.c \
						ft_wcslen.c \
						ft_wcconv.c \
						ft_wcsconv.c \
						ft_strsub.c \
						ft_strchrpos.c \
						ft_strncpy.c \
						ft_strtoupper.c \
						ft_toupper.c \
						ft_strdel.c \
						ft_free_null.c \
						ft_realloc.c \
						ft_buffer_add.c \
						ft_buffer_destroy.c \
						ft_buffer_new.c \
						ft_buffer_resize.c \
						ft_buffer_set.c \
						ft_memmove.c \

# Libft
 LIBFT_PATH = libft
 LIBFT = $(LIBFT_PATH)/libft.a

# Objects
OBJ_PATH = obj
OBJECTS = $(addprefix $(OBJ_PATH)/, $(SOURCES:%.c=%.o))
OBJECTS += $(addprefix $(OBJ_PATH)/, $(LIBFT_SRCS:%.c=%.o))

# Rules
all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "\n-------------------------------------------------"
	@echo "|\033[32;1m\t$(NAME) has been created !\t\033[0m|"
	@echo "-------------------------------------------------\n"

$(OBJECTS): $(HEADERS) | $(OBJ_PATH)
$(OBJECTS): $(OBJ_PATH)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_PATH):
	@-mkdir -p $@

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31mall files.o are deleted\033[0m\t\t|"
	@echo "-----------------------------------------\n"

fclean: clean
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
