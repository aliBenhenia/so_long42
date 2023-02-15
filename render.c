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
			if (data->map[f][a] == '1')
				mlx_put_image_to_window(data->mlx, data->wind, data->img[0], a * 30, f * 30);
			else if (data->map[f][a] == 'C')
				mlx_put_image_to_window(data->mlx, data->wind, data->img[1], a * 30, f * 30);
			else if (data->map[f][a] == 'P' && dt->fx == -1)
			{
				dt->fx = a * 30;
				dt->fy = f * 30;
				mlx_put_image_to_window(data->mlx, data->wind, data->img[2], a * 30, f * 30);
			}
			else if (data->map[f][a] == 'E')
			{
				if (data->coins == 1)
					mlx_put_image_to_window(data->mlx, data->wind, data->img[5], a * 30, f * 30);
				mlx_put_image_to_window(data->mlx, data->wind, data->img[3], a * 30, f * 30);
			}
			a++;
		}
		f++;
	}
}
