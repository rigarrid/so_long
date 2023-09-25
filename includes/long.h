/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:51:24 by rigarrid          #+#    #+#             */
/*   Updated: 2023/09/25 18:14:43 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include <mlx.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_vector
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

typedef struct s_reference
{
	void		*floor;
	void		*wall;
	void		*exit;
	void		*coin;
	void		*start;
	t_vector	size;
}	t_reference;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_vector	size;
}	t_mlx;

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

int		ft_error(int ne);
void	ft_matrix(t_map *world);
int		ft_getmap(t_map *world);
int		ft_items(t_map *world, int x, int y);
int		ft_checkmap(t_map *world);
int		ft_search(t_map world, t_tiles *col, int x, int y);
int		ft_beatmap(t_map world);

#endif