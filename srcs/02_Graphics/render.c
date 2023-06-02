/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:39:50 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 20:29:47 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* convert txt map caracteres to image */
void	parse_chars(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->img.wall, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->img.sea, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		turn_ship(data, width, i);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->img.exit_l, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->img.yellow_ping, width, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'W')
		mlx_put_image_to_window(data->mlx, data->win, \
								data->img.enemy, width, i * IMG_SIZE);
}

/* Put (animated) images to the map*/
int	render(t_data *data)
{
	int		i;
	size_t	j;
	int		width;

	if (data->win == NULL)
		return (FAILURE);
	i = 0;
	j = 0;
	width = 0;
	mlx_wait(data);
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			parse_chars(data, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		j = 0;
		width = 0;
		i++;
		data->img.cicle++;
	}
	compute_enemy_move_up_down(data);
	compute_enemy_move_right_left(data);
	player_lose(data);
	return (SUCCESS);
}
