/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:47:29 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/09 13:12:31 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	usage(void)
{
	ft_outputstr(2, "usage: ./Cub3D input_file [--save]\n\
	input_file: a .cub map file\n\
	--save: save first rendered image as bitmap");
}

void	safe_exit(int e)
{
	if (e != OK)
		ft_outputstr(2, "Error\n");

	if (e == INC_FORM)
		ft_outputstr(2, "Incorrect file format.\n");
	else if (e == INC_READ)
		ft_outputstr(2, "File reading interrupted.\n");
	else if (e == INC_TXID)
		ft_outputstr(2, "Incorrect texture ID\n");

	if (e >= USAGE && e <= INC_FLAG)
		usage();

	if (e == OK)
		exit(0);

	exit(1);
}

char	*read_line(int fd, char **line)
{
	int		n;
	char	*buf;
	char	**split;

	n = -1;
	while (n && !ft_strchr(*line, '\n') && (buf = ft_strnew(64)))
	{
		if (!(n = read(fd, buf, 64)) && *line == NULL)
			return (NULL);
		if (n == -1)
			safe_exit(INC_READ);
		*line = ft_strjoinfreefirst(*line, buf);
		ft_strdel(&buf);
	}
	if (!n && (buf = ft_strdup(*line)))
		ft_strdel(line);
	else
	{
		split = ft_strsplit(*line, '\n');
		buf = ft_strjoinfreefirst(split[0], "");
		ft_strdel(line);
		*line = ft_strjoinfreefirst(split[1], "");
		ft_memdel((void **)&split);
	}
	return (buf);
}

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
	char	*tmp;

	tmp = ft_strdup("");
	while ((line = read_line(fd, &tmp)))
		ft_outputstr(1, line);

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

void	check_flag(char *flag, t_options *opts)
{
	if (!flag)
		safe_exit(INC_FLAG);

	if (ft_strcmp("--", flag) != 2)
		safe_exit(INC_FLAG);

	flag += 2;
	if (ft_strequ("save", flag))
		opts->save = 1;
}

void	check_format(char *file)
{
	size_t l;

	if (!file)
		safe_exit(INC_FORM);

	l = ft_strlen(file);
	if (!ft_strequ(".cub", file + l - 4))
		safe_exit(INC_FORM);
}

void	parse_input(int ac, char **av, t_meta *meta)
{
	check_format(av[1]);
	if (ac == 3)
		check_flag(av[2], meta->opts);

	check_content(av[1], meta);
}

int		main(int ac, char **av)
{
	t_meta		*meta;

	meta = (t_meta *)malloc(sizeof(t_meta));
	meta->opts = (t_options *)malloc(sizeof(t_options));

	if (ac < 2 || ac > 3)
		safe_exit(USAGE);
	parse_input(ac, av, meta);

	return (0);
}
