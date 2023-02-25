/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:14:35 by abenheni          #+#    #+#             */
/*   Updated: 2023/02/14 15:14:39 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char *p[])
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static void	load_imgs(t_long *data)
{
	data->pic[0] = "./imgs/wall.xpm";
	data->pic[1] = "./imgs/coin_anm0.xpm";
	data->pic[2] = "./imgs/player.xpm";
	data->pic[3] = "./imgs/exit.xpm";
	data->img[0] = mlx_xpm_file_to_image(data->mlx,
			data->pic[0],
			&data->y,
			&data->x);
	data->img[1] = mlx_xpm_file_to_image(data->mlx,
			data->pic[1],
			&data->y, &data->x);
	data->img[2] = mlx_xpm_file_to_image(data->mlx,
			data->pic[2],
			&data->y, &data->x);
	data->img[3] = mlx_xpm_file_to_image(data->mlx,
			data->pic[3],
			&data->y, &data->x);
	if (!data->img[0] || !data->img[1] || !data->img[2] || !data->img[3])
		ft_error("error\n");
}

static void	init_data(t_long *data, t_help *dt)
{
	dt->fx = -1;
	dt->fy = -1;
	data->moves = 0;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_error("error in mlx init\n");
	}
}

static int	close1(void)
{
	exit(0);
}

int	main(int ac, char *av[])
{
	t_long	data;
	t_help	dt;

	if (ac == 1)
		ft_error("you have only one arg\n");
	if (ac > 2)
		ft_error("you have too args\n");
	parsing(av[1], &data);
	init_data(&data, &dt);
	data.wind = mlx_new_window(data.mlx,
			data.width * 30,
			data.height * 30, "so_long");
	if (data.wind == NULL)
	{
		ft_error("error in mlx windou\n");
	}
	load_imgs(&data);
	render_map(&data, &dt);
	data.x = dt.fx;
	data.y = dt.fy;
	mlx_hook(data.wind, 2, 0, move, &data);
	mlx_hook(data.wind, 17, 0, close1, NULL);
	mlx_loop(data.mlx);
	ft_free(data.map);
	return (0);
}
