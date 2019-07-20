/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 20:40:39 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/20 20:00:08 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_getcord(char *str, t_tetris *list)
{
	int		i;
	int		j;
	int		rd[2];

	i = 0;
	j = 0;
	list->cords = malloc(sizeof(t_cord) * 4);
	while (j < 4)
	{
		if (str[i] == '#')
		{
			if (j == 0)
			{
				rd[0] = i % 5;
				rd[1] = i / 5;
			}
			list->cords[j].x = (i % 5) - rd[0];
			list->cords[j].y = (i / 5) - rd[1];
			j++;
		}
		i++;
	}
}

int		ft_place_tetri(t_tetris *tetrimino, t_fillit *fillit, int j, int i)
{
	int		cord_index;

	cord_index = 0;
	while (cord_index < 4)
	{
		if (!fillit->starting_tab[j + tetrimino->cords[cord_index].y]\
		|| !fillit->starting_tab[j + tetrimino->cords[cord_index].y]\
		[i + tetrimino->cords[cord_index].x])
			return (0);
		if (fillit->starting_tab[j + tetrimino->cords[cord_index].y]\
		[i + tetrimino->cords[cord_index].x] == '.')
			cord_index++;
		else
			return (0);
	}
	cord_index = 0;
	while (cord_index < 4)
	{
		fillit->starting_tab[j + tetrimino->cords[cord_index].y]\
		[i + tetrimino->cords[cord_index].x] = tetrimino->letter;
		cord_index++;
	}
	return (1);
}

void	ft_unplace_tetri(t_tetris *terimino, char **starting_tab, int j, int i)
{
	int		cord_index;

	cord_index = 0;
	while (cord_index < 4)
	{
		starting_tab[j + terimino->cords[cord_index].y]\
		[i + terimino->cords[cord_index].x] = '.';
		cord_index++;
	}
}

int		ft_backtracking(t_tetris *head, t_fillit *fillit, int size)
{
	int		i;
	int		j;

	j = -1;
	while (fillit->starting_tab[++j] && (i = -1))
	{
		while (fillit->starting_tab[j][++i] != '\0')
		{
			if (ft_place_tetri(head, fillit, j, i))
			{
				if (!head->next)
					return (1);
				if (ft_backtracking(head->next, fillit, size))
					return (1);
				else
					ft_unplace_tetri(head, fillit->starting_tab, j, i);
			}
		}
	}
	if (head->letter == 'A')
	{
		ft_gentab(fillit, size + 1);
		ft_backtracking(head, fillit, size + 1);
	}
	return (0);
}
