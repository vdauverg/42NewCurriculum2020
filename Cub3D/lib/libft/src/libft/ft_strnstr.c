/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:29:43 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	nlen;

	if (!*needle || !needle)
		return ((char *)haystack);
	i = 0;
	nlen = ft_strlen(needle);
	while (haystack[i] && *needle && (i + nlen) <= (int)len)
	{
		if (haystack[i] == *needle)
		{
			if (!ft_strncmp((haystack + i), needle, nlen))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
