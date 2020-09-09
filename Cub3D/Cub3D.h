/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:48:05 by vdauverg          #+#    #+#             */
/*   Updated: 2020/09/09 12:30:37 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D
# include "./minilibx_opengl_20191021/mlx.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define OK 0
# define USAGE 1
# define INC_FORM 2
# define INC_FLAG 3
# define INC_READ 3
# define INC_TXID 4

typedef struct	s_options
{
	short	save;
}				t_options;

typedef struct	s_meta
{
	struct s_options	*opts;
}				t_meta;

#endif