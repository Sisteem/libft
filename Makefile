# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/20 21:20:45 by mel-idri          #+#    #+#              #
#    Updated: 2021/04/18 15:39:28 by ylagtab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	variables																   #
# **************************************************************************** #

# name
NAME = libft.a

# compilation variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

MACROS =
ifeq ($(LIBFT_EXIT_ON_ALLOC_FAIL), 1)
    MACROS = -D EXIT_ON_ALLOC_FAIL=1
endif


# libft
LIBFT_INC = libft.h
LIBFT = ft_autoalloc.o ft_nbrlen.o ft_nbrlen_base.o ft_atoi.o  \
	ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o \
	ft_islower.o ft_isprint.o ft_isspace.o ft_isupper.o ft_itoa.o \
	ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o \
	ft_lstnew.o ft_lstsearch.o ft_max.o ft_memalloc.o ft_memccpy.o \
	ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o \
	ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o \
	ft_putnbr.o ft_putnbr_fd.o ft_putnchar.o ft_putnchar_fd.o ft_putstr.o \
	ft_putstr_fd.o ft_putunbr.o ft_putunbr_fd.o ft_putunbr_base.o  \
	ft_putunbr_base_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o \
	ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_strichr.o \
	ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
	ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
	ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strrev.o \
	ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o \
	ft_toupper.o \
	ft_bigint_add.o ft_bigint_mult.o ft_bigint_power.o ft_bigint_init.o \
	ft_bigint_util.o ft_queue_new.o ft_enqueue.o ft_dequeue.o \
	ft_strglue.o ft_strjoin_free.o ft_strdup_free.o \
	ft_realloc.o ft_free_strings_array.o ft_malloc.o ft_strings_array_length.o \
	ter_l.o ter_i.o

LIBFT_OBJ = $(addprefix $(OBJS_DIR)/, ${LIBFT})

# ft_printf
PRINTF_INC = libft.h ft_printf/ft_printf.h ft_printf/ft_printf_internals.h
PRINTF = conv_di.o conv_u.o \
	conv_c.o conv_s.o \
	conv_percenatge.o \
	ft_printf.o parser.o \
	util.o apply_conv_function.o read_numbers.o
PRINTF_OBJ = $(addprefix $(OBJS_DIR)/ft_printf/, ${PRINTF})

# vector
VECTOR_INC = vector/vector.h vector/internal/vector_internal.h
VECTOR = vector_remove.o vector_push.o vector_pop_index.o vector_pop.o \
	vector_insert_all.o vector_insert.o vector_init.o vector_free.o \
	vector_get.o internal/vector_shrink.o internal/vector_grow_above.o \
	internal/vector_grow.o
VECTOR_OBJ = $(addprefix $(OBJS_DIR)/vector/, ${VECTOR})

# dynstr
STRING_INC = dyn_str/dyn_str.h dyn_str/internal/dyn_str_internal.h
STRING = dyn_str_append.o dyn_str_append_chr.o dyn_str_clone.o \
dyn_str_create.o dyn_str_delete.o dyn_str_delete_chr.o dyn_str_dup.o \
dyn_str_fill.o dyn_str_free.o dyn_str_insert.o dyn_str_insert_chr.o \
internal/dyn_str_expand.o internal/dyn_str_shrink.o internal/dyn_str_util.o
STRING_OBJ = $(addprefix $(OBJS_DIR)/dyn_str/, ${STRING})

# stack
STACK_INC = stack/stack.h
STACK = stack.o
STACK_OBJ = $(addprefix $(OBJS_DIR)/stack/, ${STACK})

ALL_OBJ = $(LIBFT_OBJ) $(VECTOR_OBJ) $(PRINTF_OBJ) $(STRING_OBJ) $(STACK_OBJ)
ALL_INC = $(LIBFT_INC) $(VECTOR_INC) $(PRINTF_INC) $(STRING_INC) $(STACK_INC)
# objects directory
OBJS_DIR = objs

# **************************************************************************** #
#	rules																	   #
# **************************************************************************** #
all: $(NAME)

$(NAME): $(ALL_OBJ)
	ar rc $(NAME) $(ALL_OBJ)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MACROS) -c $< -o $@

$(ALL_OBJ):  $(ALL_INC)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all fclean re clean
