/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:53:16 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 20:41:52 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* * Checks if Player goes to Enemy*/
void	player_lose(t_data *data)
{
	if (data->map.map[data->p_i][data->p_j] == data->map.map[data->e_i][data->e_j])
	{
		if (data->img.cicle % (39 * WAIT) == 0)
		{
			loss_move_msg(data);
			destroy(data);
		}
	}
}

void	compute_enemy_move_right_left(t_data *data)
{
    if (data->img.cicle % (9 * WAIT) == 0)
	{
        if ( data->p_i > data->e_i)
        {
		    if (data->map.map[data->e_i + 1][data->e_j] == '0' || \
                data->map.map[data->e_i + 1][data->e_j] == 'P')
            {
				data->e_i++;
				data->map.map[data->e_i - 1][data->e_j] = '0';
			}
		}        
		if (data->p_i < data->e_i)
		{
			if (data->map.map[data->e_i - 1][data->e_j] == '0' || \
			data->map.map[data->e_i - 1][data->e_j] == 'P')
			{
			data->e_i--;
			data->map.map[data->e_i + 1][data->e_j] = '0';				
			}        
		}
    	data->map.map[data->e_i][data->e_j] = 'W';
	}
    
}

void	compute_enemy_move_up_down(t_data *data)
{
    if (data->img.cicle % (9 * WAIT) == 0)
	{
        if (data->p_j < data->e_j)
        {
		    if (data->map.map[data->e_i][data->e_j - 1] == '0' || \
                data->map.map[data->e_i][data->e_j - 1] == 'P')
				{
					data->e_j--;
					data->map.map[data->e_i][data->e_j + 1] = '0';
				}
		}
		if (data->p_j > data->e_j)
		{
			if (data->map.map[data->e_i][data->e_j + 1] == '0' || \
			data->map.map[data->e_i][data->e_j + 1] == 'P')
				{
					data->e_j++;
					data->map.map[data->e_i][data->e_j - 1] = '0';
				}
		}
	 	data->map.map[data->e_i][data->e_j] = 'W';	
   	}
}
