# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <scoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 12:40:23 by scoron            #+#    #+#              #
#    Updated: 2019/03/05 06:00:21 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls

SRCS = parse_attr.c \
	   calculate_lsug.c \
	   calculate_fic.c \
	   display.c \
	   d_support.c \
	   d_file_name.c \
	   free.c \
	   loop.c \
	   loop_root_files.c \
	   loop_init.c \
	   main.c \
	   parse_args.c \
	   sort.c \
	   opt_effect.c \
	   sort_func.c \
	   d_type.c \
	   loop_in_dir.c \
	   parse_opt.c \
	   path.c \

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
