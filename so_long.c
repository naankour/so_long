/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:09:23 by naankour          #+#    #+#             */
/*   Updated: 2025/02/10 14:09:23 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(t_game *game)
{
	int	i;
	int	actual_lenght;

	game->map->grid_lenght = ft_strlen(game->map->grid[0]);
	if ( game->map->grid_lenght == game->map->grid_height)
		ft_printf("Error : The map must be rectangular.\n");
	i = 1;
	actual_lenght = ft_strlen(game->map->grid[i]);
	while(i < game->map->grid_height)
	{
		if (actual_lenght != game->map->grid_lenght)
		{
			ft_printf("Error : THe map must be rectangular.\n");
			return ;
		}
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	print_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (game->map->grid[i])
	{
		j = 0;
		while (game->map->grid[i][j])
		{
			ft_printf("%c", game->map->grid[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
void	read_map(const char *file_path, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error : Impossible d'ouvrir le fichier");
		return ;
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map = malloc(sizeof(t_map));
	game->map->grid_height = i;
	close (fd);
	if (!game->map)
	{
		free_tab(game->map->grid);
		return ;
	}
	game->map->grid = malloc(sizeof(char *) * (i + 1));
	if (!game->map->grid)
		return ;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error : Impossible d'ouvrir le fichier");
		free_tab(game->map->grid);
		return ;
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map->grid[i] = ft_substr(line, 0, (ft_strlen(line) - 1));
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map->grid[i] = NULL;
	close (fd);
	print_map(game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->ac = ac;
	game->av = av;
	read_map(av[1], game);
	is_rectangle(game);
	if (game->map)
	{
		free_tab(game->map->grid);
		free(game->map);
	}
}
