/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespaceend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:45:15 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_whitespaceend(const char *str)
{
	if (!str || !*str)
		return (NULL);

	while (*str && ft_iswhitespace(*str))
		str++;

	return ((char *)str);
}
