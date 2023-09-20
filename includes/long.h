/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:51:24 by rigarrid          #+#    #+#             */
/*   Updated: 2023/08/16 14:52:13 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LONG_H
# define LONG_H

# include <mlx.h>
# include "../libft/includes/libft.h"

typedef struct	s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_tiles
{
	int	exit;
	int	coin;
	int	start;
}				t_tiles;

typedef struct s_mlx
{
    void        *mlx_ptr;
    void        *win_ptr;
    void        *reference;
    t_vector    size;
}   t_mlx;

typedef struct	s_image 
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map
{
	char		**map;
	char		**map2;
	char		*line;
	int			fd;
	t_vector	mass;
	t_vector	start;
	t_tiles		cons;
}				t_map;

#endif