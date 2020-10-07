/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:32:23 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!*needle || !needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && *needle)
	{
		if (haystack[i] == *needle)
		{
			if (!ft_strncmp((haystack + i), needle, ft_strlen(needle)))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
