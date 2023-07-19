/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayed_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:59:56 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/18 19:04:02 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_image(t_data *data)
{
	data->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &data->imgx, &data->imgy);
	data->path = mlx_xpm_file_to_image(data->mlx,
			PATH, &data->imgx, &data->imgy);
	data->collect = mlx_xpm_file_to_image(data->mlx, 
			COLLECT, &data->imgx, &data->imgy);
	data->exit = mlx_xpm_file_to_image(data->mlx, EXIT, 
			&data->imgx, &data->imgy);
	data->wall = mlx_xpm_file_to_image(data->mlx, 
			WALL, &data->imgx, &data->imgy);
	data->window = mlx_new_window(data->mlx, 
			data->map_x * 64, data->map_y * 64, "so_long");
	data->curr_pos = 'F';
	ft_put_image(data);
}

void	ft_put_image(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y * 64)
	{
		if (data->map2[y / 64][x / 64] != '1' 
			&& data->map2[y / 64][x / 64] != '0')
			mlx_put_image_to_window(data->mlx, data->window, data->path, x, y);
		if (data->map2[y / 64][x / 64] == '1')
			mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
		else if (data->map2[y / 64][x / 64] == '0')
			mlx_put_image_to_window(data->mlx, data->window, data->path, x, y);
		else if (data->map2[y / 64][x / 64] == 'E')
			mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
		else if (data->map2[y / 64][x / 64] == 'C')
			mlx_put_image_to_window(data->mlx, 
				data->window, data->collect, x, y);
		else if (data->map2[y / 64][x / 64] == 'P')
			ft_put_image_player(data, x, y);
		ft_xy_oper(&x, &y, data);
	}
	ft_score(data);
}

void	ft_xy_oper(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

void	ft_put_image_player(t_data *data, int x, int y)
{
	if (data->curr_pos == 'F')
		mlx_put_image_to_window(data->mlx, data->window, data->player, x, y);
	else if (data->curr_pos == 'R')
		mlx_put_image_to_window(data->mlx, data->window, data->player, x, y);
	else if (data->curr_pos == 'L')
		mlx_put_image_to_window(data->mlx, data->window, data->player, x, y);
	else if (data->curr_pos == 'B')
		mlx_put_image_to_window(data->mlx, data->window, data->player, x, y);
}

void	ft_score(t_data *data)
{
	data->move_sc = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->window, 30, 30, 0xFFFFFF, "Moves count: ");
	mlx_string_put(data->mlx, data->window, 120, 30, 0xFFFFFF, data->move_sc);
	free(data->move_sc);
}
