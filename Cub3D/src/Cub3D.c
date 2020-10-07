/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:47:29 by vdauverg          #+#    #+#             */
/*   Updated: 2020/10/07 14:08:50 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3D.h>

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
		ft_outputstr(2, "Incorrect file format.");
	else if (e == INC_READ)
		ft_outputstr(2, "File reading interrupted.");
	else if (e == INC_TXID)
		ft_outputstr(2, "Incorrect texture ID");

	if (e >= USAGE && e <= INC_FLAG)
		usage();

	if (e == OK)
		exit(0);

	ft_putchar('\n');

	exit(1);
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
