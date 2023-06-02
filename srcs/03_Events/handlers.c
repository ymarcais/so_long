/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:29:32 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 17:38:49 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}

/* Escape && W.A.S.D. keyboard type*/
int	handle_keypress(int	keysym, t_data *data)
{
	data->direction = keysym;
	if (keysym == XK_Escape)
	{
		mlx_loop_end(data -> mlx);
		destroy(data);
	}
	else if (ft_strchr("wasd", keysym))
	{
		move_player(data, keysym);
	}
	return (0);
}

/* on button release destroy free and exit*/
int	handle_btnrealease(t_data *data)
{
	mlx_loop_end(data -> mlx);
	destroy(data);
	return (0);
}
