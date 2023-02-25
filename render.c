/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:02:15 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/15 14:02:17 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	norm_help(t_long *data, t_help *dt, int f, int a)
{
	int	flag;

	flag = 0;
	if (data->map[f][a] == '1')
		flag = mlx_put_image_to_window(data->mlx,
				data->wind, data->img[0], a * 30, f * 30);
	else if (data->map[f][a] == 'C')
		flag = mlx_put_image_to_window(data->mlx,
				data->wind, data->img[1], a * 30, f * 30);
	else if (data->map[f][a] == 'P' && dt->fx == -1)
	{
		dt->fx = a * 30;
		dt->fy = f * 30;
		flag = mlx_put_image_to_window(data->mlx,
				data->wind, data->img[2], a * 30, f * 30);
	}
	else if (data->map[f][a] == 'E')
	{
		flag = mlx_put_image_to_window(data->mlx,
				data->wind, data->img[3], a * 30, f * 30);
	}
	if (flag == -1)
		ft_error("error function returns -1\n");
}

void	render_map(t_long *data, t_help *dt)
{
	int	f;
	int	a;

	f = 0;
	while (f < data->height)
	{
		a = 0;
		while (a < data->width)
		{
			norm_help(data, dt, f, a);
			a++;
		}
		f++;
	}
}
