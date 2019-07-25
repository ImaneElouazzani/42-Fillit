/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 18:58:32 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/25 20:30:57 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	t_tetris	*head;
	int			num_of_tetris;

	if (argc != 2)
	{
		write(1, "usage: fillit valid_tetriminos_file\n", 30);
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	if ((head = malloc(sizeof(t_tetris))) == NULL)
		return (0);
	num_of_tetris = 0;
	head->next = NULL;
	head->cords = NULL;
	if (!(ft_readtetris(fd, head, &num_of_tetris)) || num_of_tetris >= 26)
	{
		ft_putendl("error");
		ft_freelst(head);
		return (0);
	}
	ft_solveit(&num_of_tetris, head, fd);
	return (1);
}
