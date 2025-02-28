/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:30:30 by naankour          #+#    #+#             */
/*   Updated: 2025/02/18 16:30:30 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map(const char *file_path, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error_fd(fd);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	game->map = malloc(sizeof(t_map));
	game->map->grid_height = i;
	game->map->grid = malloc(sizeof(char *) * (i + 1));
	if (!game->map->grid)
		return ;
	game->map->grid_cpy = NULL;
	read_map2(file_path, game);
}

void	read_map2(const char *file_path, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error_fd(fd);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			game->map->grid[i] = ft_substr(line, 0, (ft_strlen(line) - 1));
		else
			game->map->grid[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map->grid[i] = NULL;
	close (fd);
}
