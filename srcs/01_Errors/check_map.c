/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:16:38 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/13 14:16:04 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_chars(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'P')
				data->map.count_p++;
			if (data->map.map[data->i][data->j] == 'E')
				data->map.count_e++;
			if (data->map.map[data->i][data->j] == 'C')
				data->map.count_c++;
			data->j++;
		}
	data->j = 0;
	data->i++;
	}
	if (!data->map.count_p || !data->map.count_e || !data->map.count_c)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	check_top_bot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_edges(int row, char **map)
{
	int	i;

	i = 1;
	if (check_top_bot(0, map) == FAILURE
		|| check_top_bot(row, map) == FAILURE)
		return (FAILURE);
	while (i < row)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (ft_strchr("01CEPW", data->map.map[i][j]) == NULL)
				error_msg(ERROTHER, data);
			j++;
		}
		j = 0;
		i++;
	}
	if (check_chars(data) == FAILURE)
		error_msg(ERRCHARS, data);
	if (data->map.count_p > 1)
		error_msg(ERRPLAYER, data);
	if (check_rectangle(data) == FAILURE)
		error_msg(ERRREC, data);
	if (check_edges(data->map.line_count - 1, data->map.map) == FAILURE)
		error_msg(ERREDGES, data);
	return (SUCCESS);
}
