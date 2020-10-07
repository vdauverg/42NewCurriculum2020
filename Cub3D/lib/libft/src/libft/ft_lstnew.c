/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:17:00 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/10 16:53:54 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *node;

	if ((node = (t_list *)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			node->content = NULL;
			node->content_size = 0;
		}
		else
		{
			if ((node->content = malloc(content_size)))
			{
				ft_memcpy((node->content), content, content_size);
				node->content_size = content_size;
			}
			else
				return (NULL);
		}
	}
	else
		return (NULL);
	return (node);
}
