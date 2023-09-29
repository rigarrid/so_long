/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:51:24 by rigarrid          #+#    #+#             */
/*   Updated: 2023/09/29 16:40:20 by rigarrid         ###   ########.fr       */
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
	int			fd;
	int			xplayer;
	int			yplayer;
	int			exit;
	int			coin;
	int			start;

	char		**map;
	char		**map2;
	char		*line;

	void		*mlx_ptr;
	void		*win_ptr;

	t_vector	mass;
	t_reference	refes;
	t_vector	size;
}	t_mlx;

int		ft_error(int ne);
void	ft_matrix(t_mlx *world);
int		ft_getmap(t_mlx *world);
int		ft_items(t_mlx *world, int x, int y);
int		ft_checkmap(t_mlx *world);
int		ft_search(t_mlx world, t_tiles *col, int x, int y);
int		ft_beatmap(t_mlx world);

#endif