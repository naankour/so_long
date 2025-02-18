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
int	main(int ac, char **av)
{
	t_game	*game;

	if (ac < 2)
		return (0);
	is_ber(av[1]);
	game = malloc(sizeof(t_game));
	game->ac = ac;
	game->av = av;
	read_map(av[1], game);
	ft_parsing(game);
	return (0);
}
