/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:18:55 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/25 20:52:52 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freedouble(char **pointer)
{
	int		i;

	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer[i]);
	free(pointer);
}

void	ft_gentab(t_fillit *fillit, int size)
{
	int		i;
	int		j;

	i = 0;
	if (fillit->starting_tab)
		ft_freedouble(fillit->starting_tab);
	if ((fillit->starting_tab =\
	(char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return ;
	while (i < size)
	{
		j = 0;
		fillit->starting_tab[i] = malloc(sizeof(char *) * size + 1);
		while (j < size)
		{
			fillit->starting_tab[i][j] = '.';
			j++;
		}
		fillit->starting_tab[i][j] = '\0';
		i++;
	}
	fillit->starting_tab[i] = NULL;
}

int		ft_init_size(int num_of_tetris)
{
	int		num;
	int		i;

	num = num_of_tetris * 4;
	i = 1;
	while (i * i < num)
		i++;
	return (i);
}
