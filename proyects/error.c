/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:29:47 by despanol          #+#    #+#             */
/*   Updated: 2024/12/29 13:29:53 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	printf_error(int error)
{
	if (error == 1)
		ft_printf("Error\n Something went wrong reading the file \n");
	else if (error == 2)
		ft_printf("Error\n No valid map, free lines\n");
	else if (error == 3)
		ft_printf("Error\n No valid map, null character\n");
	else if (error == 4)
		ft_printf("Error\n No valid map, not rectangular\n");
	else if (error == 5)
		ft_printf("Error\n No valid map, no collectibles, outlet or player\n");
	else if (error == 6)
		ft_printf("Error\n No valid map, more than one exit\n");
	else if (error == 7)
		ft_printf("Error\n No valid map, more than one player\n");
	else if (error == 8)
		ft_printf("Error\n No valid map, no correct walls\n");
	else if (error == 9)
		ft_printf("Error\n No valid map, wrong way\n");
	else if (error == 10)
		ft_printf("Error\n no file founded\n");
	else if (error == 11)
		ft_printf("Error\n Data is not initialized\n");
	else if (error == 12)
		ft_printf("Error\n Invalid map\n");
	return (0);
}
