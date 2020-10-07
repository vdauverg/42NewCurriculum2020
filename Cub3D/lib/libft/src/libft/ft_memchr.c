/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:36:29 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s2;

	s2 = (const unsigned char *)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return ((void *)s);
		s2++;
		s++;
	}
	return (NULL);
}
