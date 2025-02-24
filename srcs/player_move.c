/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:16:59 by naankour          #+#    #+#             */
/*   Updated: 2025/02/24 13:32:39 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_map_after_move(t_game *game, int player_x, int player_y)
{
	if (game->is_exit && player_x == game->exit_x && player_y == game->exit_y)
		game->map->grid[player_y][player_x] = 'E';
	else
		game->map->grid[player_y][player_x] = '0';
	if (game->is_exit && game->map->grid[game->exit_y][game->exit_x] == '0')
	{
		game->map->grid[game->exit_y][game->exit_x] = 'E';
		game->is_exit = 0;
	}
	draw_map(game);
}

void	player_move_up(t_game *game, int player_x, int player_y)
{
	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y - 1][player_x] == '1')
		return ;
	if (game->map->grid[player_y - 1][player_x] == 'E'
		&& game->map->collectible != 0)
	{
		game->exit_x = player_x;
		game->exit_y = player_y - 1;
		game->is_exit = 1;
	}
	if (game->map->grid[player_y - 1][player_x] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
	}
	if (game->map->grid[player_y - 1][player_x] == 'C')
		game->map->collectible--;
	game->map->grid[player_y - 1][player_x] = 'P';
	update_map_after_move(game, player_x, player_y);
}

void	player_move_down(t_game *game, int player_x, int player_y)
{
	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y + 1][player_x] == '1')
		return ;
	if (game->map->grid[player_y + 1][player_x] == 'E'
		&& game->map->collectible != 0)
	{
		game->exit_x = player_x;
		game->exit_y = player_y + 1;
		game->is_exit = 1;
	}
	if (game->map->grid[player_y + 1][player_x] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
	}
	if (game->map->grid[player_y + 1][player_x] == 'C')
		game->map->collectible--;
	game->map->grid[player_y + 1][player_x] = 'P';
	update_map_after_move(game, player_x, player_y);
}

void	player_move_left(t_game *game, int player_x, int player_y)
{
	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y][player_x - 1] == '1')
		return ;
	if (game->map->grid[player_y][player_x - 1] == 'E'
		&& game->map->collectible != 0)
	{
		game->exit_y = player_y;
		game->exit_x = player_x -1;
		game->is_exit = 1;
	}
	if (game->map->grid[player_y][player_x - 1] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
	}
	if (game->map->grid[player_y][player_x - 1] == 'C')
		game->map->collectible--;
	game->map->grid[player_y][player_x - 1] = 'P';
	update_map_after_move(game, player_x, player_y);
}

void	player_move_right(t_game *game, int player_x, int player_y)
{
	find_player_position2(game, &player_x, &player_y);
	if (game->map->grid[player_y][player_x + 1] == '1')
		return ;
	if (game->map->grid[player_y][player_x + 1] == 'E'
		&& game->map->collectible != 0)
	{
		game->exit_y = player_y;
		game->exit_x = player_x + 1;
		game->is_exit = 1;
	}
	if (game->map->grid[player_y][player_x + 1] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
	}
	if (game->map->grid[player_y][player_x + 1] == 'C')
		game->map->collectible--;
	game->map->grid[player_y][player_x + 1] = 'P';
	update_map_after_move(game, player_x, player_y);
}
