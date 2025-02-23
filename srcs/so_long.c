/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:07:07 by naankour          #+#    #+#             */
/*   Updated: 2025/02/18 14:07:07 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_ber(char	*file_path)
{
	int	i;

	i = 0;
	while (file_path[i] != '\0')
		i++;
	if (i <= 4)
		ft_error_parsing(NULL, "Invalid file. Extension must be '.ber'.");
	if (file_path[i - 1] == 'r' && file_path[i - 2] == 'e'
		&& file_path[i - 3] == 'b' && file_path[i - 4] == '.')
		return ;
	else
		ft_error_parsing(NULL, "Invalid file. Extension must be '.ber'");
}

void	load_img(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm",
			&img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm",
			&img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&img_width, &img_height);
	draw_map(game);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			if (game->map->grid[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, j * 64, i * 64);
			else if (game->map->grid[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j * 64, i * 64);
			else if (game->map->grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, j * 64, i * 64);
			else if (game->map->grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j * 64, i * 64);
			else if (game->map->grid[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
	ft_printf("move count = %i\n", game->move_count++);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	if (keycode == W)
		player_move_up(game);
	if (keycode == S)
		player_move_down(game);
	if (keycode == A)
		player_move_left(game);
	if (keycode == D)
		player_move_right(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac < 2)
	{
		ft_error_parsing(NULL, "No file provided.");
		return (1);
	}
	if (ac == 2)
	{
		is_ber(av[1]);
		game = malloc(sizeof(t_game));
		read_map(av[1], game);
		ft_parsing(game);
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->map->grid_lenght * 64,
				game->map->grid_height * 64, "so_long");
		load_img(game);
		mlx_key_hook(game->win, key_hook, game);
		mlx_hook(game->win, 17, 0, close_game, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
