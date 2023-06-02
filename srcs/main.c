/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarcais <ymarcais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:33:11 by ymarcais          #+#    #+#             */
/*   Updated: 2023/03/14 19:07:18 by ymarcais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	static t_data	data = {0};

	if (argc == 2)
	{
		if (check_extension(argv[1]) == FAILURE)
			error_msg(ERRBER, &data);
		create_map(argv[1], &data);
		init_map(&data);
		check_map(&data);
		check_path(&data);
		ft_free(data.map.map);
		create_map(argv[1], &data);
		init_map(&data);
		init_player(&data);
		init_enemy(&data);
		init_window(&data);
		init_images(&data);
		get_img_adress(&data);
		render(&data);
		loop_images(data);
		destroy(&data);
	}
	return (0);
}
