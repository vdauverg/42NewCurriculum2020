/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:47:29 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/02 19:00:50 by vdauverg         ###   ########.fr       */
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
	if (e == INC_FORM)
		ft_outputstr(2, "Error\nIncorrect file format.\n");

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
	char	*tmpline;


	while (!ft_strchr(*line, '\n'))
	{
		buf = ft_strnew(64);
		n = read(fd, buf, 64);
		tmpline = ft_strjoin(*line, buf);
		ft_strdel(line);
		*line = tmpline;
		ft_strdel(&tmpline);
		ft_strdel(buf);
	}

	tmpline = *line;
	*line = ft_strsplit(tmpline, '\n');

	return ()
}

void	check_content(char *file, t_meta *meta)
{
	int fd;

	fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		perror("Error");
		safe_exit(USAGE);
	}


	meta = NULL;
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

int	main(int ac, char **av)
{
	t_meta		*meta;

	meta = (t_meta *)malloc(sizeof(t_meta));
	meta->opts = (t_options *)malloc(sizeof(t_options));

	if (ac < 2 || ac > 3)
		safe_exit(USAGE);
	parse_input(ac, av, meta);

	return (0);
}
