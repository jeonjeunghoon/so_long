/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:50:34 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 16:53:47 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ending(t_game *game)
{
	if (game->player->happy_ending == TRUE)
	{
		ft_exit("CLEAR !!!\n");
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	set_draw_var(game);
	x = game->draw->camera_pivot_x;
	while (x < game->draw->camera_pivot_x + game->draw->max_screen_x)
	{
		y = game->draw->camera_pivot_y;
		while (y < game->draw->camera_pivot_y + game->draw->max_screen_y)
		{
			draw_road(game, x, y);
			if (game->map->map[y][x] == WALL)
				draw_wall(game, x, y);
			else if (game->map->map[y][x] == COLLECTIBLE)
				draw_collect(game, x, y);
			else if (game->map->map[y][x] == PLAYER)
				draw_player(game, x, y);
			else if (game->map->map[y][x] == EXIT)
				draw_exit(game, x, y);
			y++;
		}
		x++;
	}
}

int	so_long(t_game *game)
{
	usleep(25000);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	if (game->player->happy_ending == TRUE || \
		game->player->bad_ending == TRUE)
		ending(game);
	return (0);
}
