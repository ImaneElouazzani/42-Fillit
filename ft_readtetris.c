/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 12:18:25 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/21 18:16:10 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_readtetris(int fd, t_tetris *head, int *num_tetris)
{
	char	str[TETRIS_SIZE + 1];
	int		re;
	char	letter;
	int		check;

	letter = 'A';
	check = 0;
	while ((re = read(fd, str, TETRIS_SIZE)) > 0)
	{
		head->next = NULL;
		head->cords = NULL;
		if ((check = 1) && re < 20)
			return (0);
		str[20] = '\0';
		if (!(ft_check_format(str, head, letter++, num_tetris)))
			return (0);
		if ((re = read(fd, str, 1)) == -1)
			return (0);
		if (re == 0)
			break ;
		if (str[0] != '\n' || !(head->next = malloc(sizeof(t_tetris))))
			return (0);
		head = head->next;
	}
	return (str[0] == '\n' || check == 0) ? 0 : 1;
}
