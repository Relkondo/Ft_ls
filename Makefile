# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <scoron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/03 12:40:23 by scoron            #+#    #+#              #
#    Updated: 2019/03/14 12:14:05 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls

S_NAME = parse_attr.c \
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

S_PATH = srcs/

SRCS = $(addprefix $(S_PATH), $(S_NAME))

O_PATH = objs/

OBJS = $(addprefix $(O_PATH), $(S_NAME:.c=.o))

HEADER = ft_ls.h

FLAGS = -Wall -Wextra -Werror

L_PATH = libft/

LIB = $(addprefix $(S_PATH), $(L_PATH))

all : $(NAME)

$(NAME) : lib $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(FLAGS) -I libft/includes -L $(LIB) -lft

$(O_PATH)%.o : $(S_PATH)%.c includes/$(HEADER)
	@mkdir -p $(O_PATH)
	@clang $(FLAGS) -I includes -c $< -o $@

clean :
	@make -C $(LIB) clean
	@/bin/rm -rf $(O_PATH)

fclean : clean
	@make -C $(LIB) fclean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C $(LIB)

test : $(NAME)
	./$(NAME)

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
