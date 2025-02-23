/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:40:43 by naankour          #+#    #+#             */
/*   Updated: 2025/02/18 14:40:43 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_grid_copy(t_game *game)
{
	int	i;

	game->map->grid_cpy = malloc(sizeof(char *) * (game->map->grid_height + 1));
	if (!game->map->grid_cpy)
		return ;
	i = 0;
	while (i < game->map->grid_height)
	{
		game->map->grid_cpy[i] = ft_strdup(game->map->grid[i]);
		i++;
	}
	game->map->grid_cpy[i] = NULL;
}

void	flood_fill(t_game *game, char fill, int y, int x)
{
	if (x < 0 || y < 0 || x > game->map->grid_lenght
		|| y > game->map->grid_height || game->map->grid_cpy[y][x] == fill
		|| game->map->grid_cpy[y][x] == '1')
		return ;
	game->map->grid_cpy[y][x] = 'F';
	flood_fill(game, fill, y - 1, x);
	flood_fill(game, fill, y + 1, x);
	flood_fill(game, fill, y, x - 1);
	flood_fill(game, fill, y, x + 1);
}

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->grid_height)
	{
		j = 0;
		while (j < game->map->grid_lenght)
		{
			if (game->map->grid_cpy[i][j] == 'P')
			{
				flood_fill(game, 'F', i, j);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	check_grid_cpy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->grid_height)
	{
		j = 0;
		while (j < game->map->grid_lenght)
		{
			if (game->map->grid_cpy[i][j] == 'E'
				|| game->map->grid_cpy[i][j] == 'C')
				ft_error_parsing(game, ERROR_PATH);
			j++;
		}
		i++;
	}
	free_tab(game->map->grid_cpy);
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
