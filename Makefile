# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avast <avast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 13:12:18 by avast             #+#    #+#              #
#    Updated: 2023/02/10 18:38:47 by avast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

STACK_UTILS = src/stack_utils/stack_add_back.c \
	src/stack_utils/stack_add_front.c \
	src/stack_utils/stack_clear.c \
	src/stack_utils/stack_create_new.c \
	src/stack_utils/stack_check_order.c \
	src/stack_utils/stack_display.c \
	src/stack_utils/stack_get_max.c \
	src/stack_utils/stack_get_min.c \
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

BONUS = checker

SRC_BONUS = bonus/src/stack_utils/stack_add_back.c \
	bonus/src/stack_utils/stack_add_front.c \
	bonus/src/stack_utils/stack_clear.c \
	bonus/src/stack_utils/stack_create_new.c \
	bonus/src/stack_utils/stack_check_order.c \
	bonus/src/stack_utils/stack_display.c \
	bonus/src/stack_utils/stack_get_size.c \
	bonus/src/stack_utils/stack_push.c \
	bonus/src/stack_utils/stack_reverse_rotate.c \
	bonus/src/stack_utils/stack_rotate.c \
	bonus/src/stack_utils/stack_rreverse_rotate.c \
	bonus/src/stack_utils/stack_rrotate.c \
	bonus/src/stack_utils/stack_sswap.c \
	bonus/src/stack_utils/stack_swap.c \
	bonus/src/stack_utils/stack_update_positions.c \
	bonus/src/main.c \
	bonus/src/parsing.c \
	bonus/src/read_instructions.c \

INCLUDES_BONUS = bonus/includes/params.h \
	bonus/includes/protos.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

LIBFT = ./libft/libft.a

LIBFTDIR = ./libft/

MAKEFLAGS += --no-print-directory

BLUE = \033[1;94m

PURPLE = \033[1;95m

GREEN = \033[1;92m

YELLOW = \033[1;93m

all: $(NAME)

bonus: $(BONUS)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -g -I./includes -I./libft -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(INCLUDES)
	@$(CC) $(OBJ) -L$(LIBFTDIR) -g -lft -o $(NAME)
	@printf "$(YELLOW)------Compilation executed------\n\n"

$(BONUS): $(OBJ_BONUS) $(LIBFT) $(INCLUDES_BONUS)
	@$(CC) $(OBJ_BONUS) -L$(LIBFTDIR) -g -lft -o $(BONUS)
	@printf "$(YELLOW)------Compilation executed------\n\n"

$(LIBFT):
	@make -C $(LIBFTDIR) 
	@printf "$(BLUE)--------Libft.a created----------\n\n"

do: all clean

clean:
	@/bin/rm -f $(OBJ) $(OBJ_BONUS)
	@make clean -C $(LIBFTDIR)
	@printf "$(PURPLE)------Object files deleted-------\n\n"

fclean: clean
	@/bin/rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIBFTDIR)
	@printf "$(GREEN)----Executable files deleted-----\n\n"

re: fclean all

.PHONY : all clean fclean re

