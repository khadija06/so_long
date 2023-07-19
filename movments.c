/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:55:46 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/18 18:56:33 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_up(int key, t_data *data)
{
	if (key == K_W || key == K_UP)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'B';
			ft_display_updated_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y - 1)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'F';
			ft_display_updated_move(data);
		}
	}
}

void	ft_check_down(int key, t_data *data)
{
	if (key == K_S || key == K_DOWN)
	{
		if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'F';
			ft_display_updated_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x, data->ply_y + 1)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_y += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'F';
			ft_display_updated_move(data);
		}
	}
}

void	ft_check_left(int key, t_data *data)
{
	if (key == K_A || key == K_LEFT)
	{
		if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'L';
			ft_display_updated_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x - 1, data->ply_y)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x -= 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'L';
			ft_display_updated_move(data);
		}
	}
}

void	ft_check_right(int key, t_data *data)
{
	if (key == K_D || key == K_RIGHT)
	{
		if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 1)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->map2[data->ex_y][data->ex_x] = 'E';
			data->curr_pos = 'R';
			ft_display_updated_move(data);
		}
		else if ((ft_check_mov(data, data->ply_x + 1, data->ply_y)) == 2)
		{
			data->map2[data->ply_y][data->ply_x] = '0';
			data->ply_x += 1;
			data->map2[data->ply_y][data->ply_x] = 'P';
			data->curr_pos = 'R';
			ft_display_updated_move(data);
		}
	}
}

int	ft_key_event(int key, t_data *data)
{
	if (key == K_ESC)
	{
		ft_close_game(data); 
		exit(EXIT_SUCCESS);
	}
	ft_check_up(key, data);
	ft_check_down(key, data);
	ft_check_left(key, data);
	ft_check_right(key, data);
	return (0);
}
