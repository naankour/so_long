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

void	ft_parsing(t_game *game)
{
	is_rectangle(game);
	only_valid_chars(game);
	check_map_items(game);
	check_map_right_left_borders(game);
	check_map_top_bottom_borders(game);
	ft_grid_copy(game);
	find_player_position(game);
	check_grid_cpy(game);
}
void	load_img(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = 64;
	img_height = 64;
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &img_width, &img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &img_width, &img_height);
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
			if( game->map->grid[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, j*64, i*64);
			else if( game->map->grid[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, j*64, i*64);
			else if( game->map->grid[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, j*64, i*64);
			else if( game->map->grid[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, j*64, i*64);
			else if( game->map->grid[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, j*64, i*64);
			j++;
		}
		i++;
	}
}

void	find_player_position2(t_game *game, int *player_x, int *player_y)
{
	*player_y = 0;
	while (game->map->grid[*player_y] != NULL)
	{
		*player_x = 0;
		while (game->map->grid[*player_y][*player_x] != '\0')
		{
			if (game->map->grid[*player_y][*player_x] == 'P')
				return;
			(*player_x)++;
		}
		(*player_y)++;
	}
}
void	player_move_up(t_game *game)
{
	int	player_x;
	int	player_y;

	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y - 1][player_x] == '1')
		return;
	if (game->map->grid[player_y - 1][player_x] == 'E' && game->map->collectible != 0)
		return;
	if (game->map->grid[player_y - 1][player_x] == 'E' && game->map->collectible == 0)
	{
		ft_printf("Congratulations! You reached the exit! ❄️\n");
		close_game(game);
	}
	if (game->map->grid[player_y - 1][player_x] == 'C')
		game->map->collectible--;
	game->map->grid[player_y - 1][player_x] = 'P';
	game->map->grid[player_y][player_x] = '0';
	draw_map(game);
}

void	player_move_down(t_game *game)
{
	int	player_x;
	int	player_y;

	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y + 1][player_x] == '1')
		return;
	if (game->map->grid[player_y + 1][player_x] == 'E' && game->map->collectible != 0)
		return;
	if (game->map->grid[player_y + 1][player_x] == 'E' && game->map->collectible == 0)
	{
		ft_printf("Congratulations! You reached the exit! ❄️\n");
		close_game(game);
	}
	if (game->map->grid[player_y + 1][player_x] == 'C')
		game->map->collectible--;
	game->map->grid[player_y + 1][player_x] = 'P';
	game->map->grid[player_y][player_x] = '0';
	draw_map(game);
}

void	player_move_left(t_game *game)
{
	int	player_x;
	int	player_y;

	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y][player_x - 1] == '1')
		return;
	if (game->map->grid[player_y][player_x - 1] == 'E' && game->map->collectible != 0)
		return;
	if (game->map->grid[player_y][player_x - 1] == 'E' && game->map->collectible == 0)
	{
		ft_printf("Congratulations! You reached the exit! ❄️\n");
		close_game(game);
	}
	if (game->map->grid[player_y][player_x - 1] == 'C')
		game->map->collectible--;
	game->map->grid[player_y][player_x - 1] = 'P';
	game->map->grid[player_y][player_x] = '0';
	draw_map(game);
}

void	player_move_right(t_game *game)
{
	int	player_x;
	int	player_y;

	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y][player_x + 1] == '1')
		return;
	if (game->map->grid[player_y][player_x + 1] == 'E' && game->map->collectible != 0)
		return;
	if (game->map->grid[player_y][player_x + 1] == 'E' && game->map->collectible == 0)
	{
		ft_printf("Congratulations! You reached the exit! ❄️\n");
		close_game(game);
	}
	if (game->map->grid[player_y][player_x + 1] == 'C')
		game->map->collectible--;
	game->map->grid[player_y][player_x + 1] = 'P';
	game->map->grid[player_y][player_x] = '0';
	draw_map(game);
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
// int	key_hook(int keycode, t_game *game)
// {
// 	int	player_x;
// 	int	player_y;
// 	int target_x;
// 	int target_y;

// 	find_player_position2(game, &player_x, &player_y);
// 	target_x = player_x;
// 	target_y = player_y;
// 	if (keycode == ESC)
// 		close_game(game);
// 	if (keycode == W)
// 		target_y -= 1;
// 	else if (keycode == A)
// 		target_x -= 1;
// 	else if (keycode == S)
// 		target_y += 1;
// 	else if (keycode == D)
// 		target_x += 1;
// 	if (game->map->grid[target_y][target_x] == 'E')
// 	{
// 		if (game->map->collectible > 0)
// 			return (0);
// 		else
// 		{
// 			ft_printf("❄️ Congratulations! You escaped the snowy labyrinth!❄️\n");
// 			close_game_win(game);
// 		}
// 	}
// 	if (game->map->grid[target_y][target_x] == '0' || game->map->grid[target_y][target_x] == 'C')
// 	{
// 		if (game->map->grid[target_y][target_x] == 'C')
// 			game->map->collectible--;
// 		game->map->grid[player_y][player_x] = '0';
// 		game->map->grid[target_y][target_x] = 'P';
// 		draw_map(game);
// 	}
// 	return (0);
// }
// int	key_hook(int keycode, t_game *game)
// {
// 	int	player_x;
// 	int	player_y;

// 	find_player_position2(game, &player_x, &player_y);
// 	if (keycode == ESC)
// 		close_game(game);
// 	if (keycode == W)
// 	{
// 		if (game->map->grid[player_y - 1][player_x] == '0' ||
// 			game->map->grid[player_y - 1][player_x] == 'C')
// 		{
// 			if (game->map->grid[player_y - 1][player_x] == 'C')
// 				game->map->collectible--;
// 			ft_printf("%d\n", game->map->collectible);
// 			game->map->grid[player_y][player_x] = '0';
// 			game->map->grid[player_y - 1][player_x] = 'P';
// 			draw_map(game);
// 		}
// 	}
// 	if (keycode == S)
// 	{
// 		if (game->map->grid[player_y + 1][player_x] == '0' ||
// 			game->map->grid[player_y + 1][player_x] == 'C')
// 		{
// 			if (game->map->grid[player_y + 1][player_x] == 'C')
// 				game->map->collectible--;
// 			ft_printf("%d\n", game->map->collectible);
// 			game->map->grid[player_y][player_x] = '0';
// 			game->map->grid[player_y + 1][player_x] = 'P';
// 			draw_map(game);
// 		}
// 	}
// 	if (keycode == D)
// 	{
// 		if (game->map->grid[player_y][player_x + 1] == '0' ||
// 			game->map->grid[player_y][player_x + 1] == 'C')
// 		{
// 			if (game->map->grid[player_y][player_x + 1] == 'C')
// 				game->map->collectible--;
// 			ft_printf("%d\n", game->map->collectible);
// 			game->map->grid[player_y][player_x] = '0';
// 			game->map->grid[player_y][player_x + 1] = 'P';
// 			draw_map(game);
// 		}
// 	}
// 	if (keycode == A)
// 	{
// 		if (game->map->grid[player_y][player_x - 1] == '0' ||
// 			game->map->grid[player_y][player_x - 1] == 'C')
// 		{
// 			if (game->map->grid[player_y][player_x - 1] == 'C')
// 				game->map->collectible--;
// 			ft_printf("%d\n", game->map->collectible);
// 			game->map->grid[player_y][player_x] = '0';
// 			game->map->grid[player_y][player_x - 1] = 'P';
// 			draw_map(game);
// 		}
// 	}
// 	return (0);
// }

void	free_img(t_game *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
}

int	close_game(t_game *game)
{
	free_tab(game->map->grid);
	free_img(game);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	ft_printf("❄️  You’ve melted away... See you next time! ❄️\n");
	exit(0);
	return (0);
}
int	close_game_win(t_game *game)
{
	free_tab(game->map->grid);
	free_img(game);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
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
		game->win = mlx_new_window(game->mlx, game->map->grid_lenght*64, game->map->grid_height*64, "so_long");
		load_img(game);
		ft_printf("%d\n", game->map->collectible);
		mlx_key_hook(game->win, key_hook, game);
		mlx_hook(game->win, 17, 0, close_game, game);
		mlx_loop(game->mlx);
	}
	return (0);
}




















