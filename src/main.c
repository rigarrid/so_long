#include "../includes/long.h"
#include <stdio.h>

void	ft_graphic(char tile, t_mlx	window)
{
	t_mlx	wall;
	t_mlx	floor;

	window.size.x *= 64;
	window.size.y *= 64;
	floor.reference = mlx_xpm_file_to_image(window.mlx_ptr, "textures/floor.xpm", 
	&floor.size.x, &floor.size.y);
	wall.reference = mlx_xpm_file_to_image(window.mlx_ptr, "textures/wall.xpm", 
	&wall.size.x, &wall.size.y);
	if (tile == '1')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, wall.reference, window.size.x, window.size.y);
	if (tile == '0')
		mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, floor.reference, window.size.x, window.size.y);
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

/*
Función que se encarga de almacenar el mapa en una matriz,
tambien almacena cuantas lineas y columnas hay.
- INT world->mass.y = Nº lineas
- INT world->mass.x = Nº columnas
- CHAR ** world->map = matriz con el mapa almacenado
*/

static void	ft_getmap(t_map *world)
{
	int	c;

	c = 0;
	world->fd = open("test.ber", O_RDONLY);
	while((world->line = get_next_line(world->fd)) != NULL)
	{
		if (world->mass.y == 0)
			world->mass.x = ft_strlen(world->line) - 1;
		world->mass.y++;
	}
	close(world->fd);
	world->map = (char **)ft_calloc(sizeof(char *) * (world->mass.y + 1), 1);
	world->fd = open("test.ber", O_RDONLY);
	while((world->line = get_next_line(world->fd)) != NULL)
	{
		world->map[c] = ft_substr(world->line, 0, world->mass.x);
		c++;
	}
}

static int ft_check(t_map *world)
{
	t_vector	nav;
	t_tiles		til;

	nav.x = 0;
	nav.y = 0;
	til.exit = 0;
	til.coin = 0;
	til.start = 0;
	if (world->mass.x == world->mass.y)
	{
		ft_printf("ERROR.\nThe map its not a rectangle.\n");
		return (1);
	}
	while (world->map[nav.y] != NULL)
	{

		if (world->map[nav.y][nav.x] == '\n' || world->map[nav.y][nav.x] == '\0')
		{
			nav.x = 0;
			nav.y++;
		}
		else if ((world->map[0][nav.x] != '1') || (world->map[nav.y][0] != '1') || 
		(world->map[world->mass.y - 1][nav.x]) != '1')
		{
			ft_printf("ERROR.\nThe map its not sorrounded by walls.\n");
			return (1);
		}
		else if ((world->map[nav.y][nav.x] != '1') && (world->map[nav.y][nav.x] != '0') && 
		(world->map[nav.y][nav.x] != 'C') && (world->map[nav.y][nav.x] != 'E') && 
		(world->map[nav.y][nav.x] != 'P'))
		{
			ft_printf("ERROR\nThere is a %c in the map", world->map[nav.y][nav.x]);
			return (1);
		}
		else if (world->map[nav.y][nav.x] == 'E')
			til.exit++;
		else if (world->map[nav.y][nav.x] == 'C')
			til.coin++;
		else if (world->map[nav.y][nav.x] == 'P')
			til.start++;
		else
			nav.x++;
	}
	/*if (til.exit != 1 || til.start != 1 || til.coin == 0)
	{
		ft_printf("ERROR\nThere is a problem with the exit/start/coins\n");
		return (1);
	}*/
	return (0);
}

int main()
{
	char	*line;
	int		check;
	t_mlx	window;
	t_map	world;

	ft_getmap(&world);
	if ((check = ft_check(&world)) == 0)
	{
		window.mlx_ptr = mlx_init();
		window.win_ptr = mlx_new_window(window.mlx_ptr, 1920, 1080, "Alpha 2");
		world.fd = open("test.ber", O_RDONLY);
		while ((line = get_next_line(world.fd)) != NULL)
		{
			ft_visual(line, &window);
			window.size.y++;
		}
		close(world.fd);
		mlx_loop(window.mlx_ptr);
	}
    /*if (argc != 2)
		ft_printf("Invalid number of arguments!\n");
	world.fd = open(argv[1], O_RDONLY);
	if (world.fd < 0)
		ft_printf("File not found!\n");
	else if (ft_strncmp(argv[1], ".ber", 4))
		ft_printf("Invalid file type, use .ber!\n");
	close(world.fd);*/
}