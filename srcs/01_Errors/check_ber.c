/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:33:33 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/13 14:09:28 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_extension(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	if (open(path, O_DIRECTORY) >= 0)
	{
		fd = open(path, O_DIRECTORY);
		close(fd);
		return (FAILURE);
	}
	else
	{
		fd = open(path, O_RDONLY);
		close(fd);
		if ((path[len -3] != 'b' && path[len - 2] != 'e')
			&& path[len - 1] != 'r'
			&& (path[len - 4] != '.' || fd < 0))
			return (FAILURE);
		else
			return (SUCCESS);
	}
}
