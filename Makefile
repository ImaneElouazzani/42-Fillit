NAME = fillit
all : $(NAME)

objs = main.o check_format.o ft_backtracking.o ft_printtab.o ft_readtetris.o ft_tabs_utils.o lst_utils.o ft_solveit.o

$(NAME) : $(objs)
	gcc -Wall -Werror -Wextra $(objs) libft.a -o fillit

%.o : %.c
	gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	rm -f *.o 

fclean : clean
	rm -f $(NAME)

re : fclean
	make