/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:48:05 by vdauverg          #+#    #+#             */
/*   Updated: 2020/10/07 13:40:32 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D
# include "../lib/libmlx/mlx.h"
# include "../lib/libft/inc/libft.h"
# include "../lib/libft/inc/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define OK 0
# define USAGE 1
# define INC_FORM 2
# define INC_FLAG 3
# define INC_READ 4
# define INC_TXID 5

typedef struct	s_options
{
	short	save;
}				t_options;

typedef struct	s_meta
{
	struct s_options	*opts;
	void				*ntex;
	void				*etex;
	void				*stex;
	void				*wtex;
	void				*sprite;
	int					ccol[3];
	int					fcol[3];
}				t_meta;

void			usage(void);
void			safe_exit(int e);
int				check_filepath(char *file);
void			parse_input(int ac, char **av, t_meta *meta);
void			check_format(char *file);
void			check_flag(char *flag, t_options *opts);
void			check_content(char *file, t_meta *meta);
void			check_meta(int fd, t_meta *meta);
void			check_texture(char *id, char *line);

#endif
