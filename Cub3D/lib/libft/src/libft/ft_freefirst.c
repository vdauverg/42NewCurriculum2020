/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freefirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:49:29 by vincent           #+#    #+#             */
/*   Updated: 2020/09/10 19:31:49 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_freefirst(char *s1, char *s2, char *(*f)(const char *s1, const char *s2))
{
	char	*str;
	
	str = f(s1, s2);
	ft_strdel(&s1);

	return (str);
}
