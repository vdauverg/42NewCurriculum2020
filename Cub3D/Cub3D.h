/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:48:05 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/14 13:30:05 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./minilibx_opengl_20191021/mlx.h"
# include "./Libft/inc/libft.h"
# include "./Libft/inc/get_next_line.h"
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
}				t_meta;

#endif