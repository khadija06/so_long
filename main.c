/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:35:59 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/18 18:51:38 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->map1)
		free(data->map1);
	if (data->map2)
	{
		while (data->map2[i])
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
}

int	ft_close_game(t_data *data)
{
	ft_free_mlx(data);
	ft_free_all(data);
	exit(EXIT_SUCCESS);
}

int	ft_error(char *output, t_data *data)
{
	ft_printf("%s", output);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **argv)
{
	t_data	*data;

	if (ac == 2)
	{
		data = ft_calloc(sizeof(t_data), 1);
		ft_check_map(argv[1], data);
		ft_get_map(data, argv[1]);
		ft_check_map_charcters(data);
		ft_check_lenth_map(data);
		ft_wall(data);
		ft_validmap(data, data->ply_x, data->ply_y);
		ft_path(data);
		data->mlx = mlx_init();
		ft_image(data);
		mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
		mlx_hook(data->window, 17, 1L << 2, ft_close_game, data);
		mlx_loop(data->mlx);
	}
	else
	{
		data = ft_calloc(sizeof(t_data), 1);
		ft_printf("Error!\nNo map as an argument!\n");
		ft_error("Try ./so_long <name of map>.ber\n", data);
	}
}
