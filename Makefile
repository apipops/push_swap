# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avast <avast@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 13:12:18 by avast             #+#    #+#              #
#    Updated: 2023/02/13 10:53:47 by avast            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

STACK_UTILS = mandatory/src/stack_utils/stack_add_back.c \
	mandatory/src/stack_utils/stack_add_front.c \
	mandatory/src/stack_utils/stack_clear.c \
	mandatory/src/stack_utils/stack_create_new.c \
	mandatory/src/stack_utils/stack_check_order.c \
	mandatory/src/stack_utils/stack_display.c \
	mandatory/src/stack_utils/stack_get_max.c \
	mandatory/src/stack_utils/stack_get_min.c \
	mandatory/src/stack_utils/stack_get_elem_sup.c \
	mandatory/src/stack_utils/stack_get_size.c \
	mandatory/src/stack_utils/stack_push.c \
	mandatory/src/stack_utils/stack_reverse_rotate.c \
	mandatory/src/stack_utils/stack_rotate.c \
	mandatory/src/stack_utils/stack_rreverse_rotate.c \
	mandatory/src/stack_utils/stack_rrotate.c \
	mandatory/src/stack_utils/stack_sswap.c \
	mandatory/src/stack_utils/stack_swap.c \
	mandatory/src/stack_utils/stack_update_positions.c \
	mandatory/src/stack_utils/stack_update_infos.c \

INSTRUCTION_UTILS = mandatory/src/instruction_utils/instru_add_back.c \
	mandatory/src/instruction_utils/instru_clear.c \
	mandatory/src/instruction_utils/instru_create_new.c \
	mandatory/src/instruction_utils/instru_display.c\
	mandatory/src/instruction_utils/instru_execute.c \
	mandatory/src/instruction_utils/instru_get_size.c \

SRC = mandatory/src/parsing.c \
	mandatory/src/main.c \
	mandatory/src/median.c \
	mandatory/src/instructions.c \
	mandatory/src/sort_mini.c \
	mandatory/src/sort_maxi.c \
	$(STACK_UTILS) $(INSTRUCTION_UTILS)

OBJ = $(SRC:.c=.o)

INCLUDES = mandatory/includes/params.h \
	mandatory/includes/protos.h

BONUS = checker

SRC_BONUS = bonus/src/main.c \
	bonus/src/parsing.c \
	bonus/src/sorting.c \
	bonus/src/stack_utils/stack_add_back.c \
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

INCLUDES_BONUS = bonus/includes/params.h \
	bonus/includes/protos.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

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
	@$(CC) $(FLAGS) -I./includes -I./libft -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(INCLUDES)
	@$(CC) $(OBJ) -L$(LIBFTDIR) $(FLAGS) -lft -o $(NAME)
	@printf "$(YELLOW)------Compilation executed------\n\n"

$(BONUS): $(OBJ_BONUS) $(LIBFT) $(INCLUDES_BONUS)
	@$(CC) $(OBJ_BONUS) -L$(LIBFTDIR) -g -lft -o $(BONUS)
	@printf "$(YELLOW)------Compilation executed------\n\n"

$(LIBFT):
	@make -C $(LIBFTDIR) 
	@printf "$(BLUE)--------Libft.a created----------\n\n"

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

