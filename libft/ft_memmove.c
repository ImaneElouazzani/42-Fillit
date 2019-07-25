/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:42:50 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/04 07:18:23 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			cmp;
	unsigned char	*src1;
	unsigned char	*dst1;

	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	if (src + len >= dst && src < dst)
		cmp = 1;
	else
		cmp = 0;
	i = cmp ? len - 1 : 0;
	while ((cmp && i + 1 > 0) || (!cmp && i < len))
	{
		dst1[i] = src1[i];
		i = cmp ? i - 1 : i + 1;
	}
	return (dst);
}
