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

INCLUDES = -I ./libft/

OBJDIR = obj

SRC = main.c\
	  check_validation.c\
	  actions_with_lists.c\
	  actions_for_map.c\
	  solve_fillit.c

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

CC = gcc

all: $(NAME)

$(NAME): obj_dir  $(LIBFT) $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
			echo "Fillit has been complied!"

obj_dir:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
			$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

$(LIBFT):
			make -sC ./libft/

clean:
			rm -rf $(OBJDIR)
				make fclean -sC ./libft/

fclean: clean
			rm -f $(NAME)
				make fclean -sC ./libft/

re: fclean all

.PHONY: all, re, clean, fclean obj_dir
