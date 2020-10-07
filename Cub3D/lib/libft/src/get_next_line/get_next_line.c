/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:07:53 by vincent           #+#    #+#             */
/*   Updated: 2020/09/11 18:03:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

int	get_next_line(const int fd, char **line)
{
	static char	*fdlist[4096];
	char		*buf;
	int			n;

	if (!line || fd < 0 || !(*line = ft_strnew(0)) || fd >= 4096)
		return (-1);
	buf = NULL;
	n = -1;
	
	if (fdlist[fd] && *fdlist[fd])
		*line = ft_freefirst(fdlist[fd], *line, &ft_strjoin);
	
	while (n && !buf && !(buf = ft_strchr(*line, '\n')))
	{
		buf = ft_strnew(BUFF_SIZE);
		n = read(fd, buf, BUFF_SIZE);
		if (!buf)
			return (-1);
		*line = ft_freefirst(*line, buf, &ft_strjoin);
		ft_strdel(&buf);
	}

	if (buf && *buf && !(*buf = '\0'))
		fdlist[fd] = ft_strdup(buf + 1);

	return ((n) ? 1 : 0);
}
