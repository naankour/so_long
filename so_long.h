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
	int		grid_lenght;
	int		grid_height;
}			t_map;

typedef struct s_game
{
	int		ac;
	char	**av;
	t_map	*map;
}			t_game;

#endif