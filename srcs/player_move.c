/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:16:59 by naankour          #+#    #+#             */
/*   Updated: 2025/02/23 17:16:59 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_position2(t_game *game, int *player_x, int *player_y)
{
	*player_y = 0;
	while (game->map->grid[*player_y] != NULL)
	{
		*player_x = 0;
		while (game->map->grid[*player_y][*player_x] != '\0')
		{
			if (game->map->grid[*player_y][*player_x] == 'P')
				return ;
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
		return ;
	if (game->map->grid[player_y - 1][player_x] == 'E'
		&& game->map->collectible != 0)
		return ;
	if (game->map->grid[player_y - 1][player_x] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
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
		return ;
	if (game->map->grid[player_y + 1][player_x] == 'E'
		&& game->map->collectible != 0)
		return ;
	if (game->map->grid[player_y + 1][player_x] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
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
		return ;
	if (game->map->grid[player_y][player_x - 1] == 'E'
		&& game->map->collectible != 0)
		return ;
	if (game->map->grid[player_y][player_x - 1] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
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
		return ;
	if (game->map->grid[player_y][player_x + 1] == 'E'
		&& game->map->collectible != 0)
		return ;
	if (game->map->grid[player_y][player_x + 1] == 'E'
		&& game->map->collectible == 0)
	{
		ft_printf("❄️  Congratulations! You reached the exit! ❄️\n");
		close_game_win(game);
	}
	if (game->map->grid[player_y][player_x + 1] == 'C')
		game->map->collectible--;
	game->map->grid[player_y][player_x + 1] = 'P';
	game->map->grid[player_y][player_x] = '0';
	draw_map(game);
}
