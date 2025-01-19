/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:41:13 by despanol          #+#    #+#             */
/*   Updated: 2024/12/29 14:41:15 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

typedef struct all_important_data
{
	void			*ptr_mlx;
	void			*ptr_win;
	void			*img;
	int				img_w;
	int				img_h;
	char			**read_map;
	size_t			m_width;
	size_t			m_height;
	int				player_x;
	int				player_y;
	char			*img_path;
	int				movements;
	int				collect;
	int				exit;
	int				*prgm;
}	t_data;

typedef struct check_map
{
	size_t	height;
	size_t	width;
	int		exit_map;
	int		player;
	int		barrier;
	char	**map_cpy;
	int		collect;
}	t_check_map;

# define ESC_KEY 65307
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363
# define WIDTH
# define HEIGHT
# define BACKGROUND "./assets/background2.xpm"
# define PLAYER "./assets/pac_man_0.xpm"
# define COLLECT "./assets/spr_cherry_0.xpm"
# define EXIT "./assets/spr_pacdeath_2.xpm"
# define WALL "./assets/spr_ghost_blue_0.xpm"
# define BUFFER_SIZE 4096

void	map_free(char **map);
int		exit_win(t_data *prgm);
void	open_wnd(t_data *wnd);
int		key_hook(int keycode, t_data *prgm);
void	run_game_window(t_data *data);
void	put_player(t_data *data, int x, int y);
void	put_image(t_data *data, int x, int y, char *img_path);
int		ft_print_map(t_data *data);
char	**read_map(int fd, t_data *data);
char	**file_checker(char *file);
int		move_up(t_data *prgm);
int		move_down(t_data *prgm);
int		move_left(t_data *prgm);
int		move_right(t_data *prgm);
int		flood_fill(t_check_map *map, size_t x, size_t y);
int		check_the_path(t_check_map *check_map, t_data *data);
int		aux_characters_checker(t_check_map *check_map, t_data *data);
int		check_characters(t_check_map *check_map, t_data *data);
int		map_checker(t_data *data);
int		printf_error(int error);

#endif
