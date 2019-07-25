/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:54:59 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/04 07:16:49 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	size_t			k;

	k = 0;
	ch = c;
	while (k < n)
	{
		if (((unsigned char*)src)[k] == ch)
		{
			((unsigned char*)dst)[k] = ch;
			return (dst + k + 1);
		}
		else
			((unsigned char*)dst)[k] = ((unsigned char*)src)[k];
		k++;
	}
	return (NULL);
}
