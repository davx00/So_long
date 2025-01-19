/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:41:00 by despanol          #+#    #+#             */
/*   Updated: 2024/12/29 14:41:02 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_win(t_data *prgm)
{
	if (prgm->exit == 1)
		ft_printf("You win!\n");
	else
		ft_printf("You lose!\n");
	mlx_destroy_window(prgm->ptr_mlx, prgm->ptr_win);
	map_free(prgm->read_map);
	exit(0);
}

void	open_wnd(t_data *wnd)
{
	wnd->ptr_mlx = mlx_init();
	wnd->ptr_win = mlx_new_window(wnd->ptr_mlx, wnd->img_w,
			wnd->img_h, "so_long");
	wnd->m_height = 0;
	ft_print_map(wnd);
	mlx_key_hook(wnd->ptr_win, key_hook, wnd);
}

int	key_hook(int keycode, t_data *prgm)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(prgm->ptr_mlx, prgm->ptr_win);
		map_free(prgm->read_map);
		exit(0);
	}
	if (keycode == UP_KEY)
		move_up(prgm);
	if (keycode == LEFT_KEY)
		move_left(prgm);
	if (keycode == DOWN_KEY)
		move_down(prgm);
	if (keycode == RIGHT_KEY)
		move_right(prgm);
	return (0);
}

void	run_game_window(t_data *data)
{
	if (!data || !data->read_map)
	{
		ft_printf("Error\nData or read_map is not initialized\n");
		return ;
	}
	data->m_width = ft_strlen(data->read_map[0]);
	data->m_height = 0;
	while (data->read_map[data->m_height])
		data->m_height++;
	data->ptr_mlx = mlx_init();
	if (!data->ptr_mlx)
	{
		ft_printf("Error\nFailed to initialize mlx or create window\n");
		return ;
	}
	data->ptr_win = mlx_new_window(data->ptr_mlx, data->m_width * 32,
			data->m_height * 32, "so_long");
	ft_print_map(data);
	mlx_key_hook(data->ptr_win, key_hook, data);
	mlx_hook(data->ptr_win, 17, 0, exit_win, data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (printf_error(1), 1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_printf("Error\nFailed to allocate memory for data\n"), 1);
	data->read_map = read_map(open(argv[1], O_RDONLY), data);
	if (!data->read_map)
		return (ft_printf("Error\nFailed to read map\n"), free(data), 1);
	if (!map_checker(data))
	{
		printf_error(12);
		map_free(data->read_map);
		free(data);
		return (1);
	}
	run_game_window(data);
	mlx_loop(data->ptr_mlx);
	map_free(data->read_map);
	free(data);
	return (0);
}
