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

void	ft_error_parsing(t_game *game, const char *str)
{
	if (game)
	{
		free_tab(game->map->grid);
		free(game->map);
		free(game);
	}
	ft_printf("Error : %s\n", str);
	exit(1);
}

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

void	is_rectangle(t_game *game)
{
	int	i;
	int	actual_lenght;

	game->map->grid_lenght = ft_strlen(game->map->grid[0]);
	if ( game->map->grid_lenght == game->map->grid_height)
		ft_error_parsing(game, "The map must be rectangular.");
	i = 1;
	actual_lenght = ft_strlen(game->map->grid[i]);
	while(i < game->map->grid_height)
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
	int	exit = 0;
	int	player = 0;
	int	collectible = 0;

	i = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (game->map->grid[i] != NULL)
	{
		j = 0;
		while (game->map->grid[i][j] != '\0')
		{
			if(game->map->grid[i][j] == 'P')
				player++;
			else if(game->map->grid[i][j] == 'E')
				exit++;
			else if(game->map->grid[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if ( player > 1 || player < 1 || exit > 1 || exit < 1 || collectible < 1)
		ft_error_parsing(game, "Map must have 1 'P', 1 'E', and at least 1 'C'.");
}

void	check_map_left_border(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->grid[i] != NULL)
	{
		if (game->map->grid[i][0] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");

		i++;
	}
}

void	check_map_right_border(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map->grid[i][j] != '\0')
		j++;
	j--;
	while(game->map->grid[i] != NULL)
	{
		if(game->map->grid[i][j] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		i++;
	}
}

void	check_map_bottom_border(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->grid[i] != NULL)
		i++;
	i--;
	j = 0;
	while (game->map->grid[i][j] != '\0')
	{
		if (game->map->grid[i][j] != '1')
		{
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		}
		j++;
	}
}
void	check_map_top_border(t_game *game)
{
	int	j;

	j = 0;
	while(game->map->grid[0][j] != '\0')
	{
		if(game->map->grid[0][j] != '1')
			ft_error_parsing(game, "Borders must be entirely composed of '1'.");
		j++;
	}
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
		exit(1);
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
		ft_printf("Error : Impossible d'ouvrir le fichier\n");
		free_tab(game->map->grid);
		return ;
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if( line[ft_strlen(line) - 1] == '\n')
			game->map->grid[i] = ft_substr(line, 0, (ft_strlen(line) - 1));

		else
			game->map->grid[i] = ft_strdup(line);
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

	is_ber(av[1]);
	game = malloc(sizeof(t_game));
	game->ac = ac;
	game->av = av;
	read_map(av[1], game);
	is_rectangle(game);
	only_valid_chars(game);
	check_map_items(game);
	check_map_left_border(game);
	check_map_right_border(game);
	check_map_top_border(game);
	check_map_bottom_border(game);
	if (game)
	{
		free_tab(game->map->grid);
		free(game->map);
		free(game);
	}
}

