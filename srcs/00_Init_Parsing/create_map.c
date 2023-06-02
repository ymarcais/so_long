/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:23:01 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 14:13:35 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
//#include "get_next_line.h"

void	ft_memdel(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_memdel((void **)&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	free_all(t_data *data)
{
	ft_free(data->img.tab_img_enemy);
	ft_free(data->img.tab_img_yellow_ping);
	ft_memdel((void **)& data->img.img_adress);
	ft_memdel((void **)& data->img.list_adress);
	ft_memdel((void **)& data->img.yellow_ping_adress);
	ft_memdel((void **)& data->img.enemy_adress);
	if (data->map.map)
		ft_free(data->map.map);
}

/* count nb of lines*/
int	count_line_number(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Error\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	get_map(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc((int)ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
		{
			ft_free(data->map.map);
			return ;
		}
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}
