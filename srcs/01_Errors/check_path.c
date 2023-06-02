/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:25:28 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/13 14:22:49 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*count number of zero on the map*/

void	count_zero(t_data *data)
{
	data->count_zero = 0;
	data->i = 0;
	data->j = 0;
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == '0')
				data->count_zero++;
			data->j++;
		}
	data->i++;
	data->j = 0;
	}
}

/* Replace 0 by x*/
void	check_around_x(t_data *data)
{
	data->i = 0;
	data->j = 0;
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'E' || \
				data->map.map[data->i][data->j] == 'x')
			{
				if (data->map.map[data->i - 1][data->j] == '0')
					data->map.map[data->i - 1][data->j] = 'x';
				if (data->map.map[data->i + 1][data->j] == '0')
					data->map.map[data->i + 1][data->j] = 'x';
				if (data->map.map[data->i][data->j - 1] == '0')
					data->map.map[data->i][data->j - 1] = 'x';
				if (data->map.map[data->i][data->j + 1] == '0')
					data->map.map[data->i][data->j + 1] = 'x';
			}
			data->j++;
		}
		data->i++;
		data->j = 0;
	}
}

/* Check existing x around E*/
int	check_around_exit(t_data *data)
{
	data->i = 0;
	data->j = 0;
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'P')
			{
				if (data->map.map[data->i - 1][data->j] == 'x' || \
					data->map.map[data->i + 1][data->j] == 'x' || \
					data->map.map[data->i][data->j - 1] == 'x' || \
					data->map.map[data->i][data->j + 1] == 'x')
					return (1);
			}
			data->j++;
		}
		data->i++;
		data->j = 0;
	}
	return (0);
}

int	check_path(t_data *data)
{
	int	cur;

	data->check_exit = 3;
	cur = 0;
	count_zero(data);
	while (cur < data->count_zero)
	{
		check_around_x(data);
		cur++;
	}
	data->check_exit = check_around_exit(data);
	if (data->check_exit != 1)
		error_msg(ERREXIT, data);
	return (SUCCESS);
}
