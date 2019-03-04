# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <scoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 12:40:23 by scoron            #+#    #+#              #
#    Updated: 2019/03/04 23:24:17 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls

SRCS = attributes.c \
	   calculate.c \
	   calculate2.c \
	   display.c \
	   display2.c \
	   file_name.c \
	   free.c \
	   loop.c \
	   loop_files.c \
	   loop_init.c \
	   main.c \
	   parse.c \
	   sort.c \
	   sort_assign.c \
	   sort_func.c \
	   sort_func_r.c \
	   support.c \
	   type.c \
	   loop_valid_dir.c \

OBJS = $(SRCS:.c=.o)

HEADER = ft_ls.h

all : $(NAME)

$(NAME) : lib $(OBJS)
	@gcc -o $(NAME) $(OBJS) -I libft/includes -L libft/ -lft

%.o : %.c includes/$(HEADER)
	@clang -Wall -Wextra -Werror -I includes -c $< -o $@

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C libft/

test : $(NAME)
	./$(NAME)

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
