# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avast <avast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 13:12:18 by avast             #+#    #+#              #
#    Updated: 2023/02/10 11:43:57 by avast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

STACK_UTILS = src/stack_utils/stack_add_back.c \
	src/stack_utils/stack_add_front.c \
	src/stack_utils/stack_clear.c \
	src/stack_utils/stack_create_new.c \
	src/stack_utils/stack_check_exist.c \
	src/stack_utils/stack_check_order.c \
	src/stack_utils/stack_display.c \
	src/stack_utils/stack_dup_elem.c \
	src/stack_utils/stack_get_infos.c \
	src/stack_utils/stack_get_max.c \
	src/stack_utils/stack_get_min.c \
	src/stack_utils/stack_get_elem_inf.c \
	src/stack_utils/stack_get_elem_sup.c \
	src/stack_utils/stack_get_size.c \
	src/stack_utils/stack_push.c \
	src/stack_utils/stack_reverse_rotate.c \
	src/stack_utils/stack_rotate.c \
	src/stack_utils/stack_rreverse_rotate.c \
	src/stack_utils/stack_rrotate.c \
	src/stack_utils/stack_sswap.c \
	src/stack_utils/stack_swap.c \
	src/stack_utils/stack_update_positions.c \
	src/stack_utils/stack_update_infos.c \

INSTRUCTION_UTILS = src/instruction_utils/instru_add_back.c \
	src/instruction_utils/instru_clear.c \
	src/instruction_utils/instru_create_new.c \
	src/instruction_utils/instru_delete_one.c\
	src/instruction_utils/instru_display.c\
	src/instruction_utils/instru_execute.c \
	src/instruction_utils/instru_get_size.c \

SRC = src/parsing.c \
	src/main.c \
	src/median.c \
	src/instructions.c \
	src/sort_mini.c \
	src/sort_maxi.c \
	$(STACK_UTILS) $(INSTRUCTION_UTILS)

OBJ = $(SRC:.c=.o)

INCLUDES = includes/params.h \
	includes/protos.h

CC = gcc

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft/

MAKEFLAGS += --no-print-directory

BLUE = \033[1;94m

PURPLE = \033[1;95m

GREEN = \033[1;92m

YELLOW = \033[1;93m

all: $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -g -I./includes -I./libft -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(INCLUDES)
	@$(CC) $(OBJ) -L$(LIBFTDIR) -g -lft -o $(NAME)
	@printf "$(YELLOW)------Compilation executed------\n\n"


$(LIBFT):
	@make -C $(LIBFTDIR) 
	@printf "$(BLUE)--------Libft.a created----------\n\n"

do: all clean

clean:
	@/bin/rm -f $(OBJ) 
	@make clean -C $(LIBFTDIR)
	@printf "$(PURPLE)------Object files deleted-------\n\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBFTDIR)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

.PHONY : all clean fclean re

