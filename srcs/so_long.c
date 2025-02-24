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
		game->win = mlx_new_window(game->mlx, game->map->grid_lenght * 64,
				game->map->grid_height * 64, "so_long");
		load_img(game);
		game->is_exit = 0;
		game->exit_x = 0;
		game->exit_y = 0;
		mlx_key_hook(game->win, key_hook, game);
		mlx_hook(game->win, 17, 0, close_game, game);
		mlx_loop(game->mlx);
	}
	return (0);
}
