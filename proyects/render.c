/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:40:41 by despanol          #+#    #+#             */
/*   Updated: 2024/12/29 14:40:43 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_data *data, int x, int y)
{
	void			*img;
	int				img_width;
	int				img_height;

	data->player_x = x;
	data->player_y = y;
	img = mlx_xpm_file_to_image(data->ptr_mlx, PLAYER, &img_width, &img_height);
	if (img == NULL)
	{
		ft_printf("Error\nFailed to load player image\n");
		return ;
	}
	mlx_put_image_to_window(data->ptr_mlx, data->ptr_win, img, x
		* img_width, y * img_height);
	mlx_destroy_image(data->ptr_mlx, img);
}

void	put_image(t_data *data, int x, int y, char *img_path)
{
	void			*img;
	int				img_width;
	int				img_height;

	img = mlx_xpm_file_to_image(data->ptr_mlx, img_path,
			&img_width, &img_height);
	if (!img)
	{
		ft_printf("Error\nFailed to load image: %s\n", img_path);
		return ;
	}
	mlx_put_image_to_window(data->ptr_mlx, data->ptr_win, img, x * 32, y * 32);
	mlx_destroy_image(data->ptr_mlx, img);
}

int	ft_print_map(t_data *data)
{
	size_t	w;
	size_t	h;

	h = 0;
	w = 0;
	while (h < data->m_height)
	{
		while (w < data->m_width)
		{
			if (data->read_map[h][w] == '1')
				put_image(data, w, h, WALL);
			else if (data->read_map[h][w] == '0')
				put_image(data, w, h, BACKGROUND);
			else if (data->read_map[h][w] == 'C')
				put_image(data, w, h, COLLECT);
			else if (data->read_map[h][w] == 'E')
				put_image(data, w, h, EXIT);
			else if (data->read_map[h][w] == 'P')
				put_player(data, w, h);
			w++;
		}
		w = 0;
		h++;
	}
	return (0);
}

void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
