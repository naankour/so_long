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

void	init_cam(t_game *game)
{
	game->cam_x = 0;
	game->cam_y = 0;
	game->cam_width = 20;
	game->cam_height = 10;
	if (game->map->grid_lenght < game->cam_width)
		game->cam_width = game->map->grid_lenght;
	if (game->map->grid_height < game->cam_height)
		game->cam_height = game->map->grid_height;
}

void	update_cam_player(t_game *game)
{
	int	player_x;
	int	player_y;

	find_player_position2(game, &player_x, &player_y);
	game->cam_x = player_x - (game->cam_width / 2);
	game->cam_y = player_y - (game->cam_height / 2);
	if (game->cam_x < 0)
		game->cam_x = 0;
	if (game->cam_y < 0)
		game->cam_y = 0;
	if (game->cam_x + game->cam_width > game->map->grid_lenght)
		game->cam_x = game->map->grid_lenght - game->cam_width;
	if (game->cam_y + game->cam_height > game->map->grid_height)
		game->cam_y = game->map->grid_height - game->cam_height;
}

void	init_game(t_game *game)
{
	init_cam(game);
	update_cam_player(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->cam_width * 64,
			game->cam_height * 64, "so_long");
	game->move_count = 0;
	load_img(game);
	game->is_exit = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, close_game, game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac < 2)
		return (ft_error_parsing(NULL, "No file provided."), 1);
	if (ac > 2)
		return (ft_error_parsing(NULL, "Only one file is needed."), 1);
	if (ac == 2)
	{
		is_ber(av[1]);
		game = malloc(sizeof(t_game));
		read_map(av[1], game);
		ft_parsing(game);
		init_game(game);
		mlx_loop(game->mlx);
	}
	return (0);
}
