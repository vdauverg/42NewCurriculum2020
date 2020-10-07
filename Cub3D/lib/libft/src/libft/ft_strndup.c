/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:45:05 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dup;
	size_t	size;

	size = sizeof(char) * ft_strlen(s1);
	if (size <= n)
		dup = ft_strnew(size);
	else
		dup = ft_strnew(n);
	if (!dup)
		return (NULL);
	ft_strncpy(dup, s1, n);
	return (dup);
}
