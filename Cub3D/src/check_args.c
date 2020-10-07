/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:15:52 by vincent           #+#    #+#             */
/*   Updated: 2020/10/07 13:51:07 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Cub3D.h>

void	check_flag(char *flag, t_options *opts)
{
	if (!flag)
		safe_exit(INC_FLAG);

	if (ft_strncmp("--", flag, 2))
		safe_exit(INC_FLAG);
	
	flag += 2;
	if (ft_strequ("save", flag))
		opts->save = 1;
	else
		safe_exit(INC_FLAG);
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
