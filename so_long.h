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

# define ERROR_ITEM	"Map must have 1 'P', 1 'E', and at least 1 'C'."
# define ERROR_PATH	"Invalid path, some collectibles or exit are unreachable."
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_map
{
	char	**grid;
	char	**grid_cpy;
	int		grid_lenght;
	int		grid_height;
	int		collectible;
}			t_map;

typedef struct s_game
{
	t_map	*map;
	int		ac;
	char	**av;
	void	*mlx;
	void	*win;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_wall;
	void	*img_floor;
	int		move_count;
	int		exit_x;
	int		exit_y;
	int		is_exit;
	int		cam_x;
	int		cam_y;
	int		cam_width;
	int		cam_height;
}			t_game;

//PARSING
void	is_ber(char	*file_path);
void	read_map(const char *file_path, t_game *game);
void	read_map2(const char *file_path, t_game *game);
void	ft_parsing(t_game *game);
void	is_rectangle(t_game *game);
void	only_valid_chars(t_game *game);
void	check_map_items(t_game *game);
void	check_map_right_left_borders(t_game *game);
void	check_map_top_bottom_borders(t_game *game);
void	ft_grid_copy(t_game *game);
void	flood_fill(t_game *game, char fill, int y, int x);
void	find_player_position(t_game *game);
void	check_grid_cpy(t_game *game);
//ERROR
void	ft_error_fd(int fd);
void	ft_error_parsing(t_game *game, const char *str);
//FREE
void	free_tab(char **tab);
void	free_img(t_game *game);
//GAME
void	init_game(t_game *game);
void	load_img(t_game *game);
void	put_img(t_game *game, int i, int j);
void	draw_map(t_game *game);
void	find_player_position2(t_game *game, int *player_x, int *player_y);
void	player_move_right(t_game *game, int player_x, int player_y);
void	player_move_left(t_game *game, int player_x, int player_y);
void	player_move_up(t_game *game, int player_x, int player_y);
void	player_move_down(t_game *game, int player_x, int player_y);
void	update_map_after_move(t_game *game, int player_x, int player_y);
int		key_hook(int keycode, t_game *game);
int		close_game(t_game *game);
int		close_game_win(t_game *game);
//CAM
void	init_cam(t_game *game);
void	update_cam_player(t_game *game);

#endif