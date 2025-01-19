/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:40:08 by despanol          #+#    #+#             */
/*   Updated: 2025/01/04 16:55:47 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_lines(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		if (str[i] && (str[i] == '\n' || str[i] == '\0'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**free_bff(char *bff, int print_error)
{
	free(bff);
	printf_error(print_error);
	return (NULL);
}

char	**read_map(int fd, t_data *data)
{
	int		bytes;
	char	*bff;

	bff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!bff)
		return (NULL);
	bytes = read(fd, bff, BUFFER_SIZE);
	if (bytes <= 0)
		return (free_bff(bff, 1));
	if (!check_lines(bff))
		return (free_bff(bff, 2));
	data->read_map = ft_split(bff, '\n');
	if (!data->read_map)
		return (free_bff(bff, 3));
	free(bff);
	return (data->read_map);
}

char	**file_checker(char *file)
{
	int		fd;
	char	**map;
	t_data	data;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf_error(4);
		return (NULL);
	}
	map = read_map(fd, &data);
	close(fd);
	if (map == NULL)
	{
		free(data.read_map);
	}
	return (map);
}
