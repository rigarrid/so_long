/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:43:11 by rigarrid          #+#    #+#             */
/*   Updated: 2023/10/02 16:30:44 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/long.h"

/*
Funcion que administra el evento de pulsar las teclas W y S
*/

static void	ft_wskeys(int keycode, t_mlx *g)
{
	if (keycode == 1 && (g->map[g->yplayer + 1][g->xplayer] != '1'))
	{
		if ((g->map[g->yplayer + 1][g->xplayer] == 'E') &&
			(g->hold.coin == g->coin))
			ft_endgame(g, 1);
		else if (g->map[g->yplayer + 1][g->xplayer] != '1')
		{
			g->hold.move++;
			g->yplayer += 1;
		}
	}
	else if (keycode == 13 && (g->map[g->yplayer - 1][g->xplayer] != '1'))
	{
		if ((g->map[g->yplayer - 1][g->xplayer] == 'E') &&
			(g->hold.coin == g->coin))
			ft_endgame(g, 1);
		else if (g->map[g->yplayer - 1][g->xplayer] != '1')
		{
			g->hold.move++;
			g->yplayer -= 1;
		}
	}
}

/*
Funcion que administra el evento de pulsar las teclas A y D
*/

static void	ft_adkeys(int keycode, t_mlx *g)
{
	if (keycode == 0 && (g->map[g->yplayer][g->xplayer - 1] != '1'))
	{
		if ((g->map[g->yplayer][g->xplayer - 1] == 'E') &&
			(g->hold.coin == g->coin))
			ft_endgame(g, 1);
		else if (g->map[g->yplayer][g->xplayer - 1] != '1')
		{
			g->hold.move++;
			g->xplayer -= 1;
		}
	}
	else if (keycode == 2 && (g->map[g->yplayer][g->xplayer + 1] != '1'))
	{
		if ((g->map[g->yplayer][g->xplayer + 1] == 'E') &&
			(g->hold.coin == g->coin))
			ft_endgame(g, 1);
		else if (g->map[g->yplayer][g->xplayer + 1] != '1')
		{
			g->hold.move++;
			g->xplayer += 1;
		}
	}
}

/*
Funcion que registra los movimientos del jugador y se encarga de modificar el
mapa
*/

int	ft_move(int keycode, void *param)
{
	t_mlx	*g;

	g = (t_mlx *)param;
	g->size.y = -1;
	if (keycode >= 0 && keycode <= 13)
	{
		if (g->map[g->yplayer][g->xplayer] != 'E')
			g->map[g->yplayer][g->xplayer] = '0';
		ft_wskeys(keycode, g);
		ft_adkeys(keycode, g);
		ft_printf("Total moves: %d\n", g->hold.move);
		if (g->map[g->yplayer][g->xplayer] == 'C')
			g->hold.coin++;
		if (g->map[g->yplayer][g->xplayer] != 'E')
			g->map[g->yplayer][g->xplayer] = 'P';
		while (g->map[++g->size.y] != NULL)
			ft_visual(g->map[g->size.y], g);
	}
	else if (keycode == 53)
		ft_endgame(g, 2);
	return (0);
}
