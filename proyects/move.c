/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:39:54 by despanol          #+#    #+#             */
/*   Updated: 2024/12/29 14:39:57 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *prgm)
{
	if (prgm->read_map[prgm->player_y - 1][prgm->player_x] == '1')
		return (0);
	if (prgm->read_map[prgm->player_y - 1][prgm->player_x] == 'E')
	{
		if (prgm->exit == 1)
			exit_win(prgm);
		return (0);
	}
	if (prgm->read_map[prgm->player_y - 1][prgm->player_x] == 'C')
	{
		prgm->collect--;
		if (prgm->collect == 0)
			prgm->exit = 1;
	}
	prgm->read_map[prgm->player_y][prgm->player_x] = '0';
	prgm->read_map[prgm->player_y - 1][prgm->player_x] = 'P';
	prgm->movements++;
	prgm->player_y--;
	ft_print_map(prgm);
	ft_printf("The number of movements done is:" "%i\n", prgm->movements);
	return (0);
}

int	move_down(t_data *prgm)
{
	if (prgm->read_map[prgm->player_y + 1][prgm->player_x] == '1')
		return (0);
	if (prgm->read_map[prgm->player_y + 1][prgm->player_x] == 'E')
	{
		if (prgm->exit == 1)
			exit_win(prgm);
		return (0);
	}
	if (prgm->read_map[prgm->player_y + 1][prgm->player_x] == 'C')
	{
		prgm->collect--;
		if (prgm->collect == 0)
			prgm->exit = 1;
	}
	prgm->read_map[prgm->player_y][prgm->player_x] = '0';
	prgm->read_map[prgm->player_y + 1][prgm->player_x] = 'P';
	prgm->player_y++;
	prgm->movements++;
	ft_print_map(prgm);
	ft_printf("The number of movements done is:" "%i\n", prgm->movements);
	return (0);
}

int	move_left(t_data *prgm)
{
	if (prgm->read_map[prgm->player_y][prgm->player_x - 1] == '1')
		return (0);
	if (prgm->read_map[prgm->player_y][prgm->player_x - 1] == 'E')
	{
		if (prgm->exit == 1)
			exit_win(prgm);
		return (0);
	}
	if (prgm->read_map[prgm->player_y][prgm->player_x - 1] == 'C')
	{
		prgm->collect--;
		if (prgm->collect == 0)
			prgm->exit = 1;
	}
	prgm->read_map[prgm->player_y][prgm->player_x] = '0';
	prgm->read_map[prgm->player_y][prgm->player_x - 1] = 'P';
	prgm->player_y--;
	prgm->movements++;
	ft_print_map(prgm);
	ft_printf("The number of movements done is:" "%i\n", prgm->movements);
	return (0);
}

int	move_right(t_data *prgm)
{
	if (prgm->read_map[prgm->player_y][prgm->player_x + 1] == '1')
		return (0);
	if (prgm->read_map[prgm->player_y][prgm->player_x + 1] == 'E')
	{
		if (prgm->exit == 1)
			exit_win(prgm);
		return (0);
	}
	if (prgm->read_map[prgm->player_y][prgm->player_x + 1] == 'C')
	{
		prgm->collect--;
		if (prgm->collect == 0)
			prgm->exit = 1;
	}
	prgm->read_map[prgm->player_y][prgm->player_x] = '0';
	prgm->read_map[prgm->player_y][prgm->player_x + 1] = 'P';
	prgm->player_y++;
	prgm->movements++;
	ft_print_map(prgm);
	ft_printf("The number of movements done is:" "%i\n", prgm->movements);
	return (0);
}
