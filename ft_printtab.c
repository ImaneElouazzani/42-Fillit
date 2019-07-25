/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <mobounya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 21:27:32 by mobounya          #+#    #+#             */
/*   Updated: 2019/07/25 19:30:05 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printtab(char **tetris)
{
	int		i;
	int		j;

	j = 0;
	while (tetris[j])
	{
		i = 0;
		while (tetris[j][i])
		{
			ft_putchar(tetris[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
