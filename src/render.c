/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:27:57 by rigarrid          #+#    #+#             */
/*   Updated: 2023/10/02 16:30:52 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

/*
Funcion que almacena las imagenes en sus respectivas variables.
*/

static void	ft_reference(t_reference *refs, t_mlx window)
{
	refs->floor = mlx_xpm_file_to_image(window.mlx_ptr, "textures/floor.xpm",
			&refs->size.x, &refs->size.y);
	refs->wall = mlx_xpm_file_to_image(window.mlx_ptr, "textures/wall.xpm",
			&refs->size.x, &refs->size.y);
	refs->coin = mlx_xpm_file_to_image(window.mlx_ptr, "textures/coin.xpm",
			&refs->size.x, &refs->size.y);
	refs->exit = mlx_xpm_file_to_image(window.mlx_ptr, "textures/exit.xpm",
			&refs->size.x, &refs->size.y);
	refs->player = mlx_xpm_file_to_image(window.mlx_ptr, "textures/player.xpm",
			&refs->size.x, &refs->size.y);
}

/*
Función que lee una string y en base a los caracteres imprime una imagen.
*/

static void	ft_graphic(char tile, t_mlx	window)
{
	window.size.x *= 64;
	window.size.y *= 64;
	ft_reference(&window.refes, window);
	if (tile == '1')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
			window.refes.wall, window.size.x, window.size.y);
	if (tile == '0')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
			window.refes.floor, window.size.x, window.size.y);
	if (tile == 'C')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
			window.refes.coin, window.size.x, window.size.y);
	if (tile == 'P')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
			window.refes.player, window.size.x, window.size.y);
	if (tile == 'E')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr,
			window.refes.exit, window.size.x, window.size.y);
}

/*
Función que se encarga de ir imprimiendo en pantalla cada linea.
*/

void	ft_visual(char *line, t_mlx *window)
{
	window->size.x = 0;
	while (line[window->size.x])
	{
		ft_graphic(line[window->size.x], *window);
		window->size.x++;
	}
}
