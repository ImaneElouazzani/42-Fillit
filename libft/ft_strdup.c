/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobounya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 19:31:35 by mobounya          #+#    #+#             */
/*   Updated: 2019/04/04 07:22:36 by mobounya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dst;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if ((dst = malloc(sizeof(*dst) * (len + 1))) == NULL)
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		dst[len] = s1[len];
		len++;
	}
	dst[len] = '\0';
	return (dst);
}
