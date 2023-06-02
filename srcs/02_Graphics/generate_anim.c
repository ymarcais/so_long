/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_anim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:44:30 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/15 13:34:34 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/* calculate nb of lines*/
int	size_of_tab(char *list_adress)
{
	char	*str;
	int		size_tab;
	int		fd;
	int		len;

	fd = 0;
	len = 0;
	fd = open(list_adress, O_RDONLY);
	size_tab = 0;
	str = get_next_line(fd);
	if (!list_adress || !str)
		return (0);
	while (str)
	{
		size_tab++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (size_tab);
}

/*calloc line with size of line && protect fd < 0*/
char	**create_img_tab(t_data *data, char *list_adress)
{
	char	**tab;
	int		fd;

	fd = 0;
	tab = ft_calloc(sizeof(char *), size_of_tab(list_adress) + 1);
	if (!tab)
	{	
		tab = NULL;
		destroy(data);
	}
	fd = open(list_adress, O_RDONLY);
	if (fd < 0)
		return (NULL);
	close (fd);
	return (tab);
}

/* get image adress from the list*/
char	**fill_tab(t_data *data, char *list_adress)
{
	char	**tab;
	char	*str;
	int		fd;
	int		i;
	int		len;

	fd = 0;
	i = 0;
	len = 0;
	fd = open(list_adress, O_RDONLY);
	tab = create_img_tab(data, list_adress);
	str = get_next_line(fd);
	while (str)
	{
		len = (int)ft_strlen(str);
		tab[i] = str;
		tab[i][len - 1] = 0;
		if (!tab[i])
			return (NULL);
		i++;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
	return (tab);
}

/*get image adress*/
void	get_img_adress(t_data *data)
{
	data->img.tab_img_enemy = fill_tab(data, ENEMY_LIST);
	data->img.tab_img_yellow_ping = fill_tab(data, YELLOW_PING_LIST);
}

/* set new image adress and wait*/
void	mlx_wait(t_data *data)
{
	static int	cic = 0;

	if (data->img.cicle % (7 * WAIT) == 0)
	{
		if (data->img.enemy)
			mlx_destroy_image(data->mlx, data->img.enemy);
		data->img.enemy = mlx_xpm_file_to_image(data->mlx, \
			data->img.tab_img_enemy[cic], &data->img.width, &data->img.height);
		if (data->img.yellow_ping)
			mlx_destroy_image(data->mlx, data->img.yellow_ping);
		data->img.yellow_ping = mlx_xpm_file_to_image(data->mlx, \
				data->img.tab_img_yellow_ping[cic], \
				&data->img.width, &data->img.height);
		if (!data->img.yellow_ping)
			destroy(data);
		cic++;
		if (cic == 15)
			cic = 0;
	}
}
