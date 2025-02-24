/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:57:09 by naankour          #+#    #+#             */
/*   Updated: 2025/02/24 11:57:09 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			&img_width, &img_height);
	draw_map(game);
}

void	put_img(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map->grid[i][j])
	{
		if (game->map->grid[i][j] == 'P')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_player, j * 64, i * 64);
		else if (game->map->grid[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit, j * 64, i * 64);
		else if (game->map->grid[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_collectible, j * 64, i * 64);
		else if (game->map->grid[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_wall, j * 64, i * 64);
		else if (game->map->grid[i][j] == '0')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_floor, j * 64, i * 64);
		j++;
	}
}

void	draw_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->grid[i])
	{
		put_img(game, i);
		i++;
	}
	ft_printf("move count = %i\n", game->move_count++);
}
