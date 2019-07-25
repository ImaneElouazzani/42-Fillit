NAME = libft.a
all : $(NAME)

objs = ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memset.o ft_memmove.o ft_tolower.o ft_toupper.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isprint.o ft_isascii.o \
	  	ft_atoi.o ft_strlen.o ft_strcpy.o ft_strcmp.o ft_strncpy.o ft_strcat.o ft_strcat.o ft_strncat.o ft_strdup.o \
		ft_strncmp.o ft_strchr.o ft_strrchr.o ft_memcmp.o ft_memchr.o ft_strstr.o ft_putchar.o ft_putstr.o \
		ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putendl.o ft_memalloc.o ft_strnew.o ft_strdel.o ft_memdel.o \
		ft_strclr.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strsub.o ft_strjoin.o ft_strtrim.o ft_itoa.o ft_strnstr.o ft_strsplit.o ft_strequ.o ft_strnequ.o \
		ft_lstnew.o  ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_strlcat.o

$(NAME) : $(objs)
	ar rc $(NAME) $(objs)

%.o : %.c
	@echo "Compiling $@"
	@gcc -Wall -Werror -Wextra -c $< -o $@

clean :
	@rm -f $(objs)

fclean : clean
	@rm -f $(NAME)

re : fclean
	make
