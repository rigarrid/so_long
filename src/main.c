/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:00:49 by rigarrid          #+#    #+#             */
/*   Updated: 2023/10/02 16:09:04 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

/*
Funcion que imprime el mensaje de finalizado y cierra el juego
*/

void	ft_endgame(t_mlx *g, int data)
{
	if (data == 1)
		ft_printf("Congratulations!. Total moves: %d\n", ++g->hold.move);
	else if (data == 2)
		ft_printf("Game closed\n");
	free(g->map);
	exit(0);
}

/*
Administra el cierre del juego mediante el boton X
*/

static int	ft_xclose(void *param)
{
	ft_endgame((t_mlx *)param, 2);
	return (0);
}

/*
Inicializa variables
*/

static void	ft_assigment(t_mlx *g)
{
	g->size.y = -1;
	g->hold.coin = 0;
	g->hold.move = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	game;

	if (argc != 2)
		ft_error(7);
	game.hold.file = argv[1];
	ft_check_file_name(game.hold.file);
	ft_assigment(&game);
	game.fd = open(game.hold.file, O_RDONLY);
	if (game.fd == -1)
		return (ft_error(5));
	if ((ft_getmap(&game) == 0) && (ft_checkmap(&game) == 0)
		&& (ft_beatmap(game) == 0))
	{
		game.mlx_ptr = mlx_init();
		game.win_ptr = mlx_new_window(game.mlx_ptr, (game.mass.x * 64),
				(game.mass.y * 64), "so_long");
		while (game.map[++game.size.y] != NULL)
			ft_visual(game.map[game.size.y], &game);
		mlx_key_hook(game.win_ptr, ft_move, &game);
		mlx_hook(game.win_ptr, 17, (1L << 17), ft_xclose, &game);
		mlx_loop(game.mlx_ptr);
	}
	return (0);
}
