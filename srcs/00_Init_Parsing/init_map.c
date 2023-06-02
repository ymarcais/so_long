/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:57 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 17:00:12 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
//#include "get_next_line.h"

void	init_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->direction = 'w';
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.enemy_kill = 0;
	data->map.can_exit = 0;
	data->steps_count = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = ((int)ft_strlen(data->map.map[0])) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
	data->img.cicle = 0;
}

//   fprintf(stderr, "Adresse2: %p\n", data->map.map);
void	create_map(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->map.line_count = count_line_number(path);
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof (char *));
	if (!(data->map.map))
		return ;
	data->map.fd = open (path, O_RDONLY);
	if (data->map.fd < 0)
		printf("Error\n");
	else
	{
		get_map(row, column, i, data);
		close(data->map.fd);
	}
}
