/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_borders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:15:26 by naankour          #+#    #+#             */
/*   Updated: 2025/02/18 14:15:26 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_rectangle(t_game *game)
{
	int	i;
	int	actual_lenght;

	game->map->grid_lenght = ft_strlen(game->map->grid[0]);
	if (game->map->grid_lenght == game->map->grid_height)
		ft_error_parsing(game, "The map must be rectangular.");
	i = 0;
	actual_lenght = ft_strlen(game->map->grid[i]);
	while (i < game->map->grid_height)
	{
		if (actual_lenght != game->map->grid_lenght)
			ft_error_parsing(game, "The map must be rectangular.");
		i++;
	}
}

void	only_valid_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i] != NULL)
	{
		j = 0;
		while (game->map->grid[i][j] != '\0')
		{
			if (game->map->grid[i][j] != '0' && game->map->grid[i][j] != '1' &&
				game->map->grid[i][j] != 'P' && game->map->grid[i][j] != 'E' &&
				game->map->grid[i][j] != 'C')
				ft_error_parsing(game, "Map contains invalid characters.");
			j++;
		}
		i++;
	}
}

void	check_map_items(t_game *game)
{
	int	i;
	int	j;
	int	exit;
	int	player;

	i = -1;
	exit = 0;
	player = 0;
	game->map->collectible = 0;
	while (game->map->grid[++i] != NULL)
	{
		j = -1;
		while (game->map->grid[i][++j] != '\0')
		{
			if (game->map->grid[i][j] == 'P')
				player++;
			else if (game->map->grid[i][j] == 'E')
				exit++;
			else if (game->map->grid[i][j] == 'C')
				game->map->collectible++;
		}
	}
	if (player > 1 || player < 1 || exit > 1 || exit < 1
		|| game->map->collectible < 1)
		ft_error_parsing(game, ERROR_ITEM);
}

void	check_map_right_left_borders(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i] != NULL)
	{
		j = 0;
		while (game->map->grid[i][j] != '\0')
			j++;
		j--;
		if (game->map->grid[i][j] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		if (game->map->grid[i][0] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		i++;
	}
}

void	check_map_top_bottom_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map->grid[0][j] != '\0')
	{
		if (game->map->grid[0][j] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		j++;
	}
	i = 0;
	while (game->map->grid[i] != NULL)
		i++;
	i--;
	j = 0;
	while (game->map->grid[i][j] != '\0')
	{
		if (game->map->grid[i][j] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		j++;
	}
}
