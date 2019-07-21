/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:58:32 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/21 18:15:01 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_tetris	*head;
	int			num_of_tetris[1];
	t_fillit	*fillit;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write(1, "usage: fillit valid_tetriminos_file\n", 30);
		return (-1);
	}
	head = malloc(sizeof(t_tetris));
	if (!(ft_readtetris(fd, head, num_of_tetris)) || num_of_tetris[0] >= 26)
	{
		ft_putendl("error");
		ft_freelst(head);
		return (0);
	}
	fillit = malloc(sizeof(t_fillit));
	fillit->starting_tab = NULL;
	ft_solveit(fillit, num_of_tetris, head);
	return (1);
}
