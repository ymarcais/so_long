/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:05:56 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 19:12:37 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Initiate window*/
int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);
	data->win = mlx_new_window(data->mlx, data->win_width, \
								data->win_height, TITRE);
	if (data->win == NULL)
	{
		free(data->win);
		return (ERROR);
	}
	return (SUCCESS);
}

/*Initiate images*/
void	init_images(t_data *data)
{
	data->img.sea = mlx_xpm_file_to_image(data->mlx, SEA, \
					&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, EXIT, \
					&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, \
					&data->img.width, &data->img.height);
	data->img.yellow_ping = mlx_xpm_file_to_image(data->mlx, YELLOW1, \
					&data->img.width, &data->img.height);
	data->img.player_up = mlx_xpm_file_to_image(data->mlx, PLAYER_UP, \
					&data->img.width, &data->img.height);
	data->img.player_down = mlx_xpm_file_to_image(data->mlx, PLAYER_DOWN, \
					&data->img.width, &data->img.height);
	data->img.player_right = mlx_xpm_file_to_image(data->mlx, PLAYER_RIGHT, \
					&data->img.width, &data->img.height);
	data->img.player_left = mlx_xpm_file_to_image(data->mlx, PLAYER_LEFT, \
					&data->img.width, &data->img.height);
	data->img.enemy = mlx_xpm_file_to_image(data->mlx, ENEMY1, \
					&data->img.width, &data->img.height);
}

/*def handle(int x int y)*/
void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, \
		&handle_btnrealease, &data);
	mlx_loop(data.mlx);
}

/*destroy images*/
void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.sea);
	mlx_destroy_image(data->mlx, data->img.player_down);
	mlx_destroy_image(data->mlx, data->img.player_left);
	mlx_destroy_image(data->mlx, data->img.player_right);
	mlx_destroy_image(data->mlx, data->img.player_up);
	mlx_destroy_image(data->mlx, data->img.exit_l);
	mlx_destroy_image(data->mlx, data->img.yellow_ping);
	mlx_destroy_image(data->mlx, data->img.enemy);
}

/*destroy and free everything*/
void	destroy(t_data *data)
{
	destroy_images(data);
	free_all(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
