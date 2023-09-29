/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:00:49 by rigarrid          #+#    #+#             */
/*   Updated: 2023/09/29 18:52:11 by rigarrid         ###   ########.fr       */
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
	refs->player = mlx_xpm_file_to_image(window.mlx_ptr, "textures/player.xpm", 
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
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.refes.player, window.size.x, window.size.y);
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

int move(int keycode, void *param)
{
	t_mlx *program = (t_mlx *)param;
	program->size.y = -1;

	if (keycode >= 0)
	{
		program->map[program->yplayer][program->xplayer] = '0';
		if (keycode == 1 && (program->map[program->yplayer + 1][program->xplayer] != '1'))
		{
			if ((program->map[program->yplayer + 1][program->xplayer] == 'E') && (program->hold.coin == program->coin))
				program->yplayer += 1;
			else if ((program->map[program->yplayer + 1][program->xplayer] == 'E') && (program->hold.coin != program->coin))
				ft_printf("You dont have enough coins to escape!\n");
			else if (program->map[program->yplayer + 1][program->xplayer] != 'E')
				program->yplayer += 1;
		}
		else if (keycode == 13 && (program->map[program->yplayer - 1][program->xplayer] != '1'))
		{
			if ((program->map[program->yplayer - 1][program->xplayer] == 'E') && (program->hold.coin == program->coin))
				program->yplayer -= 1;
			else if ((program->map[program->yplayer - 1][program->xplayer] == 'E') && (program->hold.coin != program->coin))
				ft_printf("You dont have enough coins to escape!\n");
			else if (program->map[program->yplayer - 1][program->xplayer] != 'E')
				program->yplayer -= 1;
		}
		else if (keycode == 0 && (program->map[program->yplayer][program->xplayer - 1] != '1'))
		{
			if ((program->map[program->yplayer][program->xplayer - 1] == 'E') && (program->hold.coin == program->coin))
				mlx_destroy_window(program->mlx_ptr, program->win_ptr);
			else if ((program->map[program->yplayer][program->xplayer - 1] == 'E') && (program->hold.coin != program->coin))
				ft_printf("You dont have enough coins to escape!\n");
			else if (program->map[program->yplayer][program->xplayer - 1] != 'E')
				program->xplayer -= 1;
		}
		else if (keycode == 2 && (program->map[program->yplayer][program->xplayer + 1] != '1'))
		{
			if ((program->map[program->yplayer][program->xplayer + 1] == 'E') && (program->hold.coin == program->coin))
				program->xplayer += 1;
			else if ((program->map[program->yplayer][program->xplayer + 1] == 'E') && (program->hold.coin != program->coin))
				ft_printf("You dont have enough coins to escape!\n");
			else if (program->map[program->yplayer][program->xplayer + 1] != 'E')
				program->xplayer += 1;
		}
		if (program->map[program->yplayer][program->xplayer] == 'C')
			program->hold.coin++;
		program->map[program->yplayer][program->xplayer] = 'P';
		while (program->map[++program->size.y] != NULL)
			ft_visual(program->map[program->size.y], program);
		ft_printf("monedas: %d\n", program->hold.coin);
	}
	return (0);
}

int main()
{
	t_mlx		game;

	game.size.y = -1;
	game.hold.coin = 0;
	if ((ft_getmap(&game) == 0) && (ft_checkmap(&game) == 0) && (ft_beatmap(game) == 0))
	{
		game.mlx_ptr = mlx_init();
		game.win_ptr = mlx_new_window(game.mlx_ptr, (game.mass.x * 64), (game.mass.y * 64), "Alpha 3");
		while (game.map[++game.size.y] != NULL)
			ft_visual(game.map[game.size.y], &game);
		mlx_key_hook(game.win_ptr, move, &game);
		mlx_loop(game.mlx_ptr);
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