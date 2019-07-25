/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:30:13 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/04 07:16:18 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	j;

	i = 0;
	j = c;
	while (i < n)
	{
		if (*(unsigned char *)s == j)
			return ((unsigned char*)s);
		i++;
		s++;
	}
	return (NULL);
}
