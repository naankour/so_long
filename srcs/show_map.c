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
	if (!game->img_player || !game->img_exit || !game->img_collectible
		|| !game->img_wall || !game->img_floor)
			ft_error_parsing(game, "Textures are not loaded");
	draw_map(game);
}

void	put_img(t_game *game, int i, int j)
{
	int	screen_x;
	int	screen_y;

	if (i < 0 || i >= game->map->grid_height || j < 0
		|| j >= game->map->grid_lenght)
		return ;
	screen_x = (j - game->cam_x) * 64;
	screen_y = (i - game->cam_y) * 64;
	if (game->map->grid[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, screen_x, screen_y);
	else if (game->map->grid[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, screen_x, screen_y);
	else if (game->map->grid[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collectible, screen_x, screen_y);
	else if (game->map->grid[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, screen_x, screen_y);
	else if (game->map->grid[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, screen_x, screen_y);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = game->cam_y;
	while (i < game->cam_y + game->cam_height && i < game->map->grid_height)
	{
		j = game->cam_x;
		while (j < game->cam_x + game->cam_width && j < game->map->grid_lenght)
		{
			if (i >= 0 && i < game->map->grid_height
				&& j >= 0 && j < game->map->grid_lenght)
				put_img(game, i, j);
			j++;
		}
		i++;
	}
	ft_printf("move count = %i\n", game->move_count++);
}
