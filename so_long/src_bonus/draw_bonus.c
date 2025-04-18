/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medindar <medindar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:44:52 by medindar           #+#    #+#             */
/*   Updated: 2023/09/12 12:24:50 by medindar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../mlx/mlx.h"
#include <stdlib.h>

static void	draw_data(t_game *sl);
static void	render_map(t_game *game);

static void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall_sprite, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == '0' || game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor_sprite, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->coin_sprite, x * PIXEL, y * PIXEL);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->exit_sprite, x * PIXEL, y * PIXEL);
			x++;
		}
		y++;
	}
}

static void	draw_data(t_game *sl)
{
	char	*str;

	str = ft_itoa(sl->moves);
	mlx_string_put(sl->mlx, sl->mlx_win, 20, PIXEL / 3, 0x000, "MOVES: ");
	mlx_string_put(sl->mlx, sl->mlx_win,
		PIXEL + (PIXEL / 3), PIXEL / 3, 0x000, str);
	free(str);
}

int	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	render_map(game);
	draw_data(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->dipper_sprite, game->player_x * PIXEL, game->player_y * PIXEL);
	return (0);
}
