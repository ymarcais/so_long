/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:56:22 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 20:29:31 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Check the next tile */
int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 'd' && data->map.map[data->p_i][data->p_j + 1] == tile)
		|| (direction == 'a' && data->map.map[data->p_i][data->p_j - 1] == tile)
		|| (direction == 's' && data->map.map[data->p_i + 1][data->p_j] == tile)
		|| (direction == 'w' && data->map.map[data->p_i - 1][data->p_j] == tile)
		)
		return (SUCCESS);
	else
		return (FAILURE);
}

/* * Checks when the player take an yellow_ping*/
void	collect_coins(t_data *data, char direction)
{
	if ((direction == 'd' && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == 'a' && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == 's' && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == 'w' && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

/* Turn the ship in the direction of the move*/
void	turn_ship(t_data *data, int width, int i)
{
	if (data->direction == 'd')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img.player_right, width, i * IMG_SIZE);
	else if (data->direction == 'a')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img.player_left, width, i * IMG_SIZE);
	else if (data->direction == 's')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img.player_down, width, i * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, \
			data->img.player_up, width, i * IMG_SIZE);
}

int	win_game(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		destroy(data);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

/* 
	* all the player moves
	* and count and display counter
	* player_move_to_enemy(data, direction)   */

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1') == SUCCESS || \
		(data->map.can_exit == 0 && \
		check_next_tile(data, direction, 'E') == SUCCESS))
		return ;
	data->steps_count++;
	collect_coins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	if (direction == 'd')
		data->p_j++;
	else if (direction == 'a')
		data->p_j--;
	else if (direction == 's')
		data->p_i++;
	else if (direction == 'w')
		data->p_i--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
		win_game(data);
	data->map.map[data->p_i][data->p_j] = 'P';
	printf("p_i %d // p_j %d \n", data->p_i, data->p_j);
}
