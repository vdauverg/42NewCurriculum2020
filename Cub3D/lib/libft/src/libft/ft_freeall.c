/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:57:25 by vincent           #+#    #+#             */
/*   Updated: 2020/09/10 19:31:32 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_freeall(char *s1, char *s2, char *(*f)(const char *s1, const char *s2))
{
	char	*str;
	
	str = f(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);

	return (str);
}
