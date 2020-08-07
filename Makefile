# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshala <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 15:09:06 by dshala            #+#    #+#              #
#    Updated: 2019/11/01 16:56:45 by dshala           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBHEADER = libft/includes

OBJDIR = obj

HEADER = fillit.h

SRC = main.c\
	  check_validation.c\
	  actions_with_lists.c\
	  actions_for_map.c\
	  solve_fillit.c

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

CC = gcc

all: obj_dir $(LIBFT) $(NAME)

obj_dir:
		@mkdir -p $(OBJDIR)

$(LIBFT):
		@make -sC ./libft/

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(LIBFT) -o $@ 
		@echo "Fillit has been complied!"

$(OBJDIR)/%.o: %.c $(HEADER) $(LIBHEADER) 
		@$(CC) $(FLAGS) -o $@ -c $< -I$(LIBHEADER)


clean:
		@rm -rf $(OBJDIR)
		@make fclean -sC ./libft/

fclean: clean
		@rm -f $(NAME)
		@make fclean -sC ./libft/

re: fclean all

.PHONY: all, re, clean, fclean obj_dir
