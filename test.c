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


// void	parsing2(t_game *game)
// {
// 	return ;
// }

// void	parsing(t_game *game)
// {
// 	parsing2(game);
// }

// int	main(int ac, char **av)
// {
// 	void	*mlx;
// 	t_game	game;
// 	char	**tab;

// 	game.ac = ac;
// 	game.av = av;
// 	parsing(&game);
// 	mlx = mlx_init();
// 	printf("here\n");
// }
// typedef struct s_map
// {
// 	char	**grid;
// 	int		lenght;
// 	int		height;
// }			t_map;

// t_map

// int	is_rectangle()
// {
// }
void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
void	read_map(const char *file_path)
{
	char	**grid;
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if(fd < 0)
	{
		ft_printf("Error : Ipossible d'ouvrir le fichier");
		return;
	}
	i = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		// ft_printf("%s", line);
		i++;
		free(line);
	}
	close(fd) ;

	grid = malloc(sizeof(char *) * (i + 1));
	if (!grid)
		return ;

	fd = open(file_path, O_RDONLY);
	if(fd < 0)
	{
		ft_printf("Error : Ipossible d'ouvrir le fichier");
		free_tab(grid);
		return;
	}

	i = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		// grid[i] = malloc(sizeof(char) * ft_strlen(line));
		// if (!grid[i])
		// 	return ;
		grid[i] = ft_substr(line, 0, (ft_strlen(line) - 1));
		i++;
		free(line);
	}
	close(fd);
	i = 0;
	while (grid[i])
	{
		int j = 0;
		while (grid[i][j])
		{
			ft_printf("%c", grid[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	// free_tab(grid);
	game.map->grid = grid;
}

int	main(int ac, char **av)
{
	(void)ac;
	read_map(av[1]);
}