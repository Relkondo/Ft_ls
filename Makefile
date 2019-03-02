
NAME = ft_ls

SRCS = main.c \
	   parse.c \
	   support.c \

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
