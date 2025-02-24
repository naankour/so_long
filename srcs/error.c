/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naankour <naankour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:06:58 by naankour          #+#    #+#             */
/*   Updated: 2025/02/18 14:06:58 by naankour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error: Enable to open the file.\n");
		exit(1);
	}
	return ;
}

void	ft_error_parsing(t_game *game, const char *str)
{
	if (game)
	{
		if (game->map->grid_cpy)
			free_tab(game->map->grid_cpy);
		free_tab(game->map->grid);
		free(game->map);
		free(game);
	}
	ft_printf("Error : %s\n", str);
	exit(1);
}
