/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:53:47 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 18:54:55 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* Localise player && count nb of buoys*/
void	init_player(t_data *data)
{
    int	i;
    int	j;

    i = 0;
    j = 0;
    while (data->map.map[i])
    {
        while (data->map.map[i][j])
        {
            if (data->map.map[i][j] == 'P')
            {
                data->p_i = i;
                data->p_j = j;
            }
            if (data->map.map[i][j] == 'C')
                data->map.count_c++;
            j++;
        }
    j = 0;
    i++;
    }
}

void	init_enemy(t_data *data)
{
    int	i;
    int	j;

    i = 0;
    j = 0;
    while (data->map.map[i])
    {
        while (data->map.map[i][j])
        {
            if (data->map.map[i][j] == 'W')
            {
                data->e_i = i;
                data->e_j = j;
            }
            j++;
        }
    j = 0;
    i++;
    }
}
