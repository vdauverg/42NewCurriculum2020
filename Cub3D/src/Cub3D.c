/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:47:29 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/26 18:48:00 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Cub3D.h"

void	usage(void)
{
	ft_ouputstr("Usage:\n./Cub3D [/.cub] [flag: --save]");
}

void	safe_exit(int e)
{
	if (e == INC_FORM)
		ft_outputstr("Error\nIncorrect file format.");

	if (e >= USAGE && e <= INC_FLAG)
		usage();

	exit(0);
}

void	check_flag(char *flag)
{
	if (!flag)
		safe_exit(INC_FLAG);
}

void	parse_input(int ac, char **av)
{
	check_format(av[1]);
	if (ac == 3)
		check_flag(av[2]);
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		safe_exit(USAGE);
	av = NULL;
	parse_input(ac, av);
	return (0);
}
