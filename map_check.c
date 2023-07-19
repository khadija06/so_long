/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:05:32 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/18 19:04:53 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map(char *map, t_data *data)
{
	int	len;

	len = ft_strlen(map);
	if (ft_strncmp(map + len - 4, ".ber", 4))
		ft_error("Error", data);
}

void	ft_get_map(t_data *data, char *map)
{
	int		fd;
	char	*buff;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error!\nFile don't found!\n", data);
	buff = get_next_line(fd);
	if (!buff)
		ft_error("Error!\nFile is empty!\n", data);
	while (buff)
	{
		data->map1 = ft_strjoinn(data->map1, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	free(buff);
	data->map2 = ft_split(data->map1, '\n');
	data->tmp_map2 = ft_split(data->map1, '\n');
}

void	ft_check_num_fe(t_data *data)
{
	if (data->collect_count < 1 || data->exit_count != 1
		|| data->player_count != 1)
		ft_error("Error!\nMap must include 1P or 1C or 1E.\n", data);
}

void	exit_count(t_data *data, int i, int j)
{
	data->exit_count++;
	data->ex_y = i;
	data->ex_x = j;
}

void	ft_check_map_charcters(t_data *data)
{
	static int	i = 0;
	static int	j = 0;

	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'C')
				data->collect_count++;
			else if (data->map2[i][j] == 'E')
				exit_count(data, i, j);
			else if (data->map2[i][j] == 'P')
			{
				data->player_count++;
				data->ply_x = j;
				data->ply_y = i;
			}
			else if (data->map2[i][j] != '0' && data->map2[i][j] != '1')
				ft_error("Error!\nMap must include 1P or 1C or 1E.\n", data);
			j++;
		}
		i++;
	}
	ft_check_num_fe(data);
}
