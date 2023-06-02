/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:40:48 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 20:44:16 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* 
	 * \E[ is the prefix for all ANSI escape codes.
	 * H moves the cursor to the top-left corner of the terminal screen.
	 * 2J clears the entire terminal screen.
	 * "[0m": the SGR (Select Graphic Rendition) \
	 *    parameter that resets all attributes to their default values.
 */
void	move_msg(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(RED, 1);
	printf("             U-42 Battleship \n");
	ft_putstr_fd(GREEN, 1);
	printf("You win !!! \n");
	printf("Your score:     %d \n", data->steps_count);
	if (data->map.collected > 1)
		printf("Buoys collected: %d \n", data->map.collected);
	else
		printf("Buoy collected: %d \n", data->map.collected);
	ft_putstr_fd(RESET, 1);
}

void	loss_move_msg(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(RED, 1);
	printf("             U-42 Battleship \n");
	ft_putstr_fd(GREEN, 1);
	printf("Your score is:     %d \n", data->steps_count);
	printf("You have been killed by U-Boat 42 \n");
	ft_putstr_fd(RESET, 1);
}
