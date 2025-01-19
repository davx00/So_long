/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:30:13 by despanol          #+#    #+#             */
/*   Updated: 2024/12/29 13:30:18 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_the_path(t_check_map *check_map, t_data *data)
{
	size_t	i;

	i = 0;
	check_map->map_cpy = ft_calloc(check_map->height + 1, sizeof(char *));
	if (!check_map->map_cpy)
		return (0);
	while (i < data->m_height)
	{
		check_map->map_cpy[i] = ft_strdup(data->read_map[i]);
		if (!check_map->map_cpy[i])
			return (0);
		i++;
	}
	check_map->width = data->m_width;
	check_map->height = data->m_height;
	flood_fill(check_map, data->player_x, data->player_y);
	i = 0;
	while (i < check_map->height)
	{
		if (ft_strchr(check_map->map_cpy[i], 'C')
			|| ft_strchr(check_map->map_cpy[i], 'E'))
			return (printf_error(9));
		i++;
	}
	return (1);
}

int	flood_fill(t_check_map *map, size_t x, size_t y)
{
	if (x >= map->width || y >= map->height || x < 0 || y < 0)
		return (1);
	if (map->map_cpy[y][x] == '1' || map->map_cpy[y][x] == 'V')
		return (0);
	if (map->map_cpy[y][x] == 'C' || map->map_cpy[y][x] == 'E')
		map->map_cpy[y][x] = '0';
	map->map_cpy[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
	return (1);
}

int	aux_characters_checker(t_check_map *check_map, t_data *data)
{
	if (data->read_map[check_map->height][check_map->width] != '0'
		&& data->read_map[check_map->height][check_map->width] != '1'
		&& data->read_map[check_map->height][check_map->width] != 'C'
		&& data->read_map[check_map->height][check_map->width] != 'E'
		&& data->read_map[check_map->height][check_map->width] != 'P')
		return (printf_error(5));
	else if (data->read_map[check_map->height][check_map->width] == 'C')
		check_map->collect++;
	else if (data->read_map[check_map->height][check_map->width] == 'E')
	{
		check_map->exit_map++;
		if (check_map->exit_map != 1)
			return (printf_error(6));
	}
	else if (check_map->width == 0 || check_map->height == 0
		|| check_map->width == data->m_width - 1
		|| check_map->height == data->m_height - 1)
	{
		if (data->read_map[check_map->height][check_map->width] != '1')
			return (printf_error(8));
	}
	return (1);
}

int	check_characters(t_check_map *check_map, t_data *data)
{
	while (check_map->height < data->m_height)
	{
		while (check_map->width < data->m_width)
		{
			if (!aux_characters_checker(check_map, data))
				return (0);
			else if (data->read_map[check_map->height][check_map->width] == 'P')
			{
				check_map->player++;
				data->player_x = check_map->width;
				data->player_y = check_map->height;
				if (check_map->player > 1)
					return (printf_error(7));
			}
			check_map->width++;
		}
		check_map->width = 0;
		check_map->height++;
	}
	return (1);
}

int	map_checker(t_data *data)
{
	t_check_map	*check_map;

	check_map = ft_calloc(1, sizeof(t_check_map));
	if (!check_map)
		return (0);
	check_map->height = 0;
	data->m_width = ft_strlen(data->read_map[0]);
	while (data->read_map[data->m_height])
	{
		if (ft_strlen(data->read_map[data->m_height]) != data->m_width)
			return (printf_error(4));
		data->m_height++;
	}
	if (!check_characters(check_map, data))
		return (free(check_map), 0);
	if (check_map->collect == 0 || check_map->exit_map <= 0
		|| check_map->player <= 0)
		return (printf_error(5), free(check_map), 0);
	if (!check_the_path(check_map, data))
		return (map_free(check_map->map_cpy), free(check_map), 0);
	data->collect = check_map->collect;
	map_free(check_map->map_cpy);
	free(check_map);
	return (ft_printf("Map is valid\n"), 1);
}
