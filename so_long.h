/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:59:34 by naankour          #+#    #+#             */
/*   Updated: 2025/02/10 11:59:34 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "library/libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_map
{
	char	**grid;
	char	**grid_cpy;
	int		grid_lenght;
	int		grid_height;
}			t_map;

typedef struct s_game
{
	int		ac;
	char	**av;
	t_map	*map;
}			t_game;

void	is_ber(char	*file_path);

void	ft_parsing(t_game *game);
void	read_map(const char *file_path, t_game *game);
void	read_map2(const char *file_path, t_game *game);

void	is_rectangle(t_game *game);
void	only_valid_chars(t_game *game);
void	check_map_items(t_game *game);
void	check_map_right_left_borders(t_game *game);
void	check_map_top_bottom_borders(t_game *game);

void	ft_grid_copy(t_game *game);
void	flood_fill(t_game *game, char fill, int y, int x);
void	find_player_position(t_game *game);
void	check_grid_cpy(t_game *game);

void	ft_error_fd(int fd);
void	ft_error_parsing(t_game *game, const char *str);

void	free_tab(char **tab);
#endif