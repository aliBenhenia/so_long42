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
void	load_imgs(t_long *data)
{
	data->pic[0] = "./imgs/wall.xpm";
	data->pic[1] = "./imgs/coin_anm0.xpm";
	data->pic[2] = "./imgs/player.xpm";
	data->pic[3] = "./imgs/exit.xpm";
	data->pic[4] = "./imgs/wallz.xpm";
	data->pic[5] = "./imgs/open_exit.xpm";
	data->img[0] = mlx_xpm_file_to_image(data->mlx , data->pic[0], &data->y, &data->x);
	data->img[1] = mlx_xpm_file_to_image(data->mlx , data->pic[1], &data->y, &data->x);
	data->img[2] = mlx_xpm_file_to_image(data->mlx , data->pic[2], &data->y, &data->x);
	data->img[3] = mlx_xpm_file_to_image(data->mlx , data->pic[3], &data->y, &data->x);
	data->img[4] = mlx_xpm_file_to_image(data->mlx , data->pic[4], &data->y, &data->x);
	data->img[5] = mlx_xpm_file_to_image(data->mlx , data->pic[5], &data->y, &data->x);
}
void	init_data(t_long *data, t_help *dt)
{
	dt->fx = -1;
	dt->fy = -1;
	dt->fe = -1;
	data->moves = 0;
	data->mlx = mlx_init();
}
void dd()
{
	system("leaks a.out");
}
int main(int ac, char *av[])
{
	atexit(dd);
	t_long	data;
	t_help dt;
	if (ac == 1)
		ft_error("you have only one arg\n");
	if (ac > 2)
		ft_error("you have too args\n");
	parsing(av[1],&data);
	init_data(&data,&dt);
	data.wind = mlx_new_window(data.mlx , data.width * 30, data.height * 30, "so_long");
	load_imgs(&data);
	render_map(&data, &dt);
	data.x = dt.fx;
	data.y = dt.fy;
	dt.fe = -1;
	mlx_hook(data.wind, 2, 0, move, &data);
	mlx_loop(data.mlx);
	ft_free(data.map);
	
	return (0);
}
