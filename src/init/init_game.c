/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:53:48 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/11/26 14:59:00 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_keys(t_game *game)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		game->keys[i] = 0;
		i++;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error_and_exit_free("mlx_init failed", 1, NULL);
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "Cub3D");
	if (!game->win)
		print_error_and_exit_free("mlx_init failed", 1, NULL);
	game->screen.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	if (!game->screen.img)
		print_error_and_exit_free("mlx_init failed", 1, NULL);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bpp, &game->screen.line_len, &game->screen.endian);
	init_images(game);
	game->win_game = 0;
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.angle = 0.0;
	game->player.move_speed = 0.005;
	game->player.rot_speed = 0.005;
	init_keys(game);
	game->key_left = 0;
	game->key_right = 0;
}
