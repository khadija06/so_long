/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:39:45 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/18 19:08:39 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"

# define K_ESC 53
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_UP 126
# define K_LEFT 123
# define K_DOWN 125
# define K_RIGHT 124

# define PATH "./textures/path.xpm"
# define PLAYER "./textures/player.xpm"
# define EXIT "./textures/exit.xpm"
# define WALL "./textures/wall.xpm"
# define COLLECT "./textures/collect.xpm"

typedef struct b_data
{
	void	*mlx;
	void	*path;
	void	*window;
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	char	*move_sc;
	int		move_count;
	char	curr_pos;
	int		imgy;
	int		imgx;
	char	*map1;
	char	**map2;
	char	**tmp_map2;
	int		collect_count;
	int		exit_count;
	int		player_count;
	int		ply_x;
	int		ply_y;
	int		map_x;
	int		map_y;
	int		tmp_count;
	int		valid_exit;
	int		ex_y;
	int		ex_x;
}	t_data;

int		ft_error(char *output, t_data *data);
void	ft_check_map(char *map, t_data *data);
void	ft_get_map(t_data *data, char *map);
void	ft_check_num_fe(t_data *data);
void	exit_count(t_data *data, int i, int j);
void	ft_check_map_charcters(t_data *data);
void	ft_check_lenth_map(t_data *data);
void	ft_wall(t_data *data);
void	ft_other_walls(t_data *data);
void	ft_validmap(t_data *data, int x, int y);
void	ft_path(t_data *data);
int		ft_check_mov(t_data *data, int x, int y);
void	ft_display_updated_move(t_data *data);
void	ft_image(t_data *data);
void	ft_free_mlx(t_data *data);
int		ft_key_event(int key, t_data *data);
int		ft_close_game(t_data *data);
void	ft_put_image(t_data *data);
void	ft_xy_oper(int *x, int *y, t_data *data);
void	ft_put_image_player(t_data *data, int x, int y);
void	ft_score(t_data *data);
void	ft_free_all(t_data *data);

#endif