/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:00:59 by rigarrid          #+#    #+#             */
/*   Updated: 2023/09/29 16:53:28 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

/*
Función que se encarga de almacenar el mapa en una matriz,
tambien almacena cuantas lineas y columnas hay.
- INT world->mass.y = Nº lineas
- INT world->mass.x = Nº columnas
- CHAR ** world->map = matriz con el mapa almacenado
*/

int	ft_getmap(t_mlx *world)
{
	int	c;

	c = 0;
	world->mass.y = 0;
	world->fd = open("test.ber", O_RDONLY);
	if (world->fd == -1)
		return (ft_error(5));
	world->line = get_next_line(world->fd);
	while (world->line != NULL)
	{
		if (world->mass.y++ == 0)
			world->mass.x = ft_strlen(world->line) - 1;
		world->line = get_next_line(world->fd);
	}
	ft_matrix(world);
	world->line = get_next_line(world->fd);
	while (world->line != NULL)
	{
		world->map[c] = ft_substr(world->line, 0, world->mass.x);
		world->map2[c] = ft_substr(world->line, 0, world->mass.x);
		world->line = get_next_line(world->fd);
		c++;
	}
	close(world->fd);
	return (0);
}

int	ft_items(t_mlx *world, int x, int y)
{
	while (world->map[y] != NULL)
	{
		if (world->map[y][x] == '\n' || world->map[y][x] == '\0')
			x = 0 * y++;
		else if ((world->map[0][x] != '1') || (world->map[y][0] != '1') ||
		(world->map[world->mass.y - 1][x] != '1') ||
		(world->map[y][world->mass.x - 1] != '1'))
			return (ft_error(2));
		else if ((world->map[y][x] != '1') && (world->map[y][x] != '0') &&
		(world->map[y][x] != 'C') && (world->map[y][x] != 'E') &&
		(world->map[y][x] != 'P'))
			return (ft_error(3));
		else if (world->map[y][x] == 'E')
			world->exit++;
		else if (world->map[y][x] == 'C')
			world->coin++;
		else if (world->map[y][x] == 'P')
		{
			world->start++;
			world->xplayer = x;
			world->yplayer = y;
		}
		x++;
	}
	return (0);
}

int	ft_checkmap(t_mlx *world)
{
	t_vector	nav;
	int			result;

	nav.x = 0;
	nav.y = 0;
	world->exit = 0;
	world->coin = 0;
	world->start = 0;
	if (world->mass.x == world->mass.y)
		return (ft_error(1));
	result = ft_items(world, nav.x, nav.y);
	if ((world->exit != 1 || world->start != 1
			|| world->coin == 0) && result == 0)
		return (ft_error(4));
	return (result);
}

int	ft_search(t_mlx world, t_tiles *col, int x, int y)
{
	if (world.map2[y][x] == '1')
		return (1);
	if (world.map2[y][x] == 'C')
		col->coin++;
	if (world.map2[y][x] == 'E')
		col->exit++;
	world.map2[y][x] = '1';
	if (world.map2[y][(x + 1)] != '1')
		ft_search(world, col, (x + 1), y);
	if (world.map2[(y + 1)][x] != '1')
		ft_search(world, col, x, (y + 1));
	if (world.map2[y][(x - 1)] != '1')
		ft_search(world, col, (x - 1), y);
	if (world.map2[(y - 1)][x] != '1')
		ft_search(world, col, x, (y - 1));
	if (col->coin == world.coin && col->exit == 1)
		return (0);
	return (1);
}

int	ft_beatmap(t_mlx world)
{
	t_tiles		check;
	int			x;
	int			y;
	int			result;

	x = world.xplayer;
	y = world.yplayer;
	check.coin = 0;
	check.exit = 0;
	result = ft_search(world, &check, x, y);
	if (result == 1)
		ft_printf("ERROR\nMap not beatable\n");
	return (result);
}
