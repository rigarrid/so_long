/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:00:49 by rigarrid          #+#    #+#             */
/*   Updated: 2023/09/26 18:30:22 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

void	ft_reference(t_reference *refs, t_mlx window)
{
	refs->floor = mlx_xpm_file_to_image(window.mlx_ptr, "textures/floor.xpm", 
	&refs->size.x, &refs->size.y);
	refs->wall = mlx_xpm_file_to_image(window.mlx_ptr, "textures/wall.xpm", 
	&refs->size.x, &refs->size.y);
	refs->coin = mlx_xpm_file_to_image(window.mlx_ptr, "textures/coin.xpm", 
	&refs->size.x, &refs->size.y);
	refs->exit = mlx_xpm_file_to_image(window.mlx_ptr, "textures/exit.xpm", 
	&refs->size.x, &refs->size.y);
	refs->start = mlx_xpm_file_to_image(window.mlx_ptr, "textures/start.xpm", 
	&refs->size.x, &refs->size.y);
}
void	ft_graphic(char tile, t_mlx	window)
{
	window.size.x *= 64;
	window.size.y *= 64;
	ft_reference(&window.refes, window);
	if (tile == '1')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.refes.wall, window.size.x, window.size.y);
	if (tile == '0')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.refes.floor, window.size.x, window.size.y);
	if (tile == 'C')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.refes.coin, window.size.x, window.size.y);
	if (tile == 'P')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.refes.start, window.size.x, window.size.y);
	if (tile == 'E')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.refes.exit, window.size.x, window.size.y);
}

static void	ft_visual(char *line, t_mlx *window)
{
	window->size.x = 0;
	while (line[window->size.x])
	{
		ft_graphic(line[window->size.x], *window);
		window->size.x++;
	}
}

/*int move(int keycode, void *param)
{
	t_mlx *program = (t_mlx *)param;

	//mlx_clear_window(program->mlx_ptr, program->win_ptr);
	if (keycode == 0)
		program->world.start.y -= 1;
	program->world.start.y *= 64;
	mlx_put_image_to_window(program->mlx_ptr, program->win_ptr, program->refes.exit, program->world.start.x, program->world.start.y);
	return (0);
}*/

int main()
{
	t_mlx		window;

	window.size.y = -1;
	if (ft_getmap(&window.world) == 0 && ft_checkmap(&window.world) == 0 && ft_beatmap(window.world) == 0)
	{
		window.mlx_ptr = mlx_init();
		window.win_ptr = mlx_new_window(window.mlx_ptr, (window.world.mass.x * 64), (window.world.mass.y * 64), "Alpha 3");
		while (window.world.map[++window.size.y] != NULL)
			ft_visual(window.world.map[window.size.y], &window);
		//mlx_key_hook(window.win_ptr, move, &window);
		mlx_loop(window.mlx_ptr);
	}
    /*if (argc != 2)
		ft_printf("Invalid number of arguments!\n");
	world.fd = open(argv[1], O_RDONLY);
	if (world.fd < 0)
		ft_printf("File not found!\n");
	else if (ft_strncmp(argv[1], ".ber", 4))
		ft_printf("Invalid file type, use .ber!\n");*/
	return (0);
}