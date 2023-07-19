/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:52:31 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/18 19:05:08 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_lenth_map(t_data *data)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strlen(data->map2[0]);
	data->map_x = len1;
	while (data->map2[i])
	{
		len2 = ft_strlen(data->map2[i]);
		if (len2 != len1)
			ft_error("Error!\nThe map must be rectangular.\n", data);
		i++;
	}
}

void	ft_other_walls(t_data *data)
{
	int	count;
	int	len;

	count = 0;
	len = data->map_x;
	while (count < data->map_y)
	{
		if (data->map2[count][0] != '1' || data->map2[count][len - 1] != '1')
			ft_error("Error!\nThe walls need to be closed\n", data);
		count++;
	}
	data->tmp_count = data->collect_count;
}

void	ft_wall(t_data *data)
{
	int	count_line;
	int	line;

	count_line = 0;
	line = 0;
	while (data->map2[count_line])
	{
		line++;
		count_line++;
	}
	data->map_y = line;
	count_line = 0;
	while (data->map2[0][count_line] && data->map2[line - 1][count_line])
	{
		if (data->map2[0][count_line] != '1' 
			|| data->map2[line - 1][count_line] != '1')
			ft_error("Error!\nThe walls need to be closed\n", data);
		count_line++;
	}
	ft_other_walls(data);
}

void	ft_validmap(t_data *data, int x, int y)
{
	char	*p;

	p = &data->tmp_map2[y][x];
	if (*p == 'E')
		data->valid_exit = 1;
	if (*p != '1')
	{
		if (*p == 'C')
			data->tmp_count--;
		*p = '.';
		if (data->tmp_map2[y][x + 1] != '1' &&
			data->tmp_map2[y][x + 1] != '.')
			ft_validmap(data, x + 1, y);
		if (data->tmp_map2[y][x - 1] != '1' &&
			data->tmp_map2[y][x - 1] != '.')
			ft_validmap(data, x - 1, y);
		if (data->tmp_map2[y - 1][x] != '1' &&
			data->tmp_map2[y - 1][x] != '.')
			ft_validmap(data, x, y - 1);
		if (data->tmp_map2[y + 1][x] != '1' &&
			data->tmp_map2[y + 1][x] != '.')
			ft_validmap(data, x, y + 1);
	}
}

void	ft_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->tmp_map2[i])
	{
		free(data->tmp_map2[i]);
		i++;
	}
	free(data->tmp_map2);
	if (data->tmp_count != 0 || data->valid_exit != 1)
		ft_error("Error!\nThere isn't valid way to go exit!!!\n", data);
}
