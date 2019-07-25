/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:02:18 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/25 21:05:28 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# define TETRIS_SIZE 20
# include "./libft/libft.h"

typedef struct	s_fillit
{
	char		**starting_tab;
}				t_fillit;

typedef struct	s_cord
{
	int			x;
	int			y;
}				t_cord;

typedef struct	s_tetris
{
	char			letter;
	struct s_cord	*cords;
	struct s_tetris	*next;
}				t_tetris;

void			ft_getcord(char *str, t_tetris *list);
int				ft_links(char *str);
int				ft_is_format_valid(char *str);
int				ft_readtetris(int fd, t_tetris *head, int *num_tetris);
void			ft_gentab(t_fillit *fillit, int size);
int				ft_init_size(int num_of_tetris);
int				ft_place_tetri(t_tetris *tetrimino,
				t_fillit *fillit, int j, int i);
void			ft_unplace_tetri(t_tetris *terimino,
				char **starting_tab, int j, int i);
void			ft_grow_size(t_fillit *fillit, int size);
void			ft_printtab(char **tetris);
int				ft_backtracking(t_tetris *head, t_fillit *fillit, int size);
void			ft_freelst(t_tetris *head);
void			ft_print_tetris(t_tetris *tetro);
void			ft_freedouble(char **pointer);
int				ft_check_format(char *str, t_tetris *head,\
				char letter, int *num_tetris);
void			ft_solveit(int *num, t_tetris *head, int fd);
#endif
