/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:19:56 by vincent           #+#    #+#             */
/*   Updated: 2020/10/07 13:26:53 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3D.h>

int		check_filepath(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		perror("Error");
		safe_exit(USAGE);
	}

	return (fd);
}

void	check_texture(char *id, char *line)
{
	int	l;
	int n;

	l = ft_strlen(id);
	if (strncmp(id, line, l))
		safe_exit(INC_TXID);

	n = ft_atoi(line + 1);

}

void	check_meta(int fd, t_meta *meta)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		ft_outputstr(1, line);
		ft_putchar('\n');
		ft_strdel(&line);
	}

	meta = NULL;

	// if ((line = read_line(fd, &tmp)) && line[0] == 'R')

	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
	// line = read_line(fd, &tmp);
}

void	check_content(char *file, t_meta *meta)
{
	int		fd;

	fd = check_filepath(file);

	check_meta(fd, meta);
	// check_map(fd, meta);

	if (close(fd))
		perror("Error");
}
