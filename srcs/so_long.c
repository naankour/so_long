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
int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->mlx_win);  // Détruit la fenêtre proprement
    exit(0);  // Quitte le programme
    return (0);
}
int	main(int ac, char **av)
{
	t_game	*game;
	int img_width;
	int img_height;

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
		game->mlx_win = mlx_new_window(game->mlx, 800, 600, "so_long");
		game->img = mlx_xpm_file_to_image(game->mlx, "assets/wall1.xpm", &img_width, &img_height);
		if (!game->img)
		{
			ft_printf("Erreur : Impossible de charger l'image.\n");
			return (1);  // Quitter le programme si l'image n'a pas été chargée
		}
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 100, 100);
		mlx_loop(game->mlx);
		mlx_hook(game->mlx_win, 17, 0, close_window, game);
		// mlx_hook(game->mlx_win, 17, 0, close_window, game);
		// mlx_key_hook(game->mlx_win, handle_key, game);
		// mlx_loop(game->mlx);
	}
	return (0);
}
