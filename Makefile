
NAME = ft_ls

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

HEADER = ft_ls.h

all : $(NAME)

$(NAME) : lib $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

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

comp : $(NAME) 
	clang main.c -fsanitize=address -g $(NAME) -Iincludes
	
test : comp
	./a.out

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
