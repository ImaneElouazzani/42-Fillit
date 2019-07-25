NAME = fillit
all : $(NAME)

objs = main.o check_format.o ft_backtracking.o ft_printtab.o ft_readtetris.o ft_tabs_utils.o lst_utils.o ft_solveit.o

$(NAME) : $(objs)
	make -C libft
	gcc -Wall -Werror -Wextra $(objs) ./libft/libft.a -o fillit

%.o : %.c
	@echo "compiling $@"
	@gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	rm -f $(objs)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean
	make