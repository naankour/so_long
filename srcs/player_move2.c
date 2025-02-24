/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:19:08 by naankour          #+#    #+#             */
/*   Updated: 2025/02/24 17:19:08 by naankour         ###   ########.fr       */
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

int	key_hook(int keycode, t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = 0;
	player_y = 0;
	if (keycode == ESC)
		close_game(game);
	if (keycode == W)
		player_move_up(game, player_x, player_y);
	if (keycode == S)
		player_move_down(game, player_x, player_y);
	if (keycode == A)
		player_move_left(game, player_x, player_y);
	if (keycode == D)
		player_move_right(game, player_x, player_y);
	return (0);
}
