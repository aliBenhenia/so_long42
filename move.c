#include "so_long.h"

int	move(int keycode, t_long *vars)
{
	
	if (keycode == 53)
	{
		exit(0);
	}
	if (vars->coins == 0)
	{
		dt.fe = 0;
	}
	
	if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'E' && vars->coins == 0)
	{
		ft_free(vars->map);
		exit(1);
	}
	if (keycode == 0 && vars->map[vars->y / 30 ][(vars->x - 30) / 30] != '1')
	{
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		if (dt.fe == -1 && vars->map[vars->y / 30 ][(vars->x - 30) / 30] == 'E')
			return 1 ;
		if (dt.fe == 0 && vars->map[vars->y / 30 ][(vars->x - 30) / 30] == 'E')
			exit(1) ;
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars);
		vars->x -= 30;
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		printf("moves : %d\n",vars->moves);
	}
	if (keycode == 2 && vars->map[vars->y / 30 ][(vars->x + 30) / 30] != '1')
	{
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		if (dt.fe == -1 && vars->map[vars->y / 30 ][(vars->x + 30) / 30] == 'E')
			return 1 ;
		if (dt.fe == 0 && vars->map[vars->y / 30 ][(vars->x + 30) / 30] == 'E')
			exit(1) ;
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars);
		vars->x += 30;
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		printf("moves : %d\n",vars->moves);
	}
	if (keycode == 13 && vars->map[(vars->y - 30) / 30 ][(vars->x) / 30] != '1')
	{
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		if (dt.fe == -1 && vars->map[(vars->y - 30) / 30 ][(vars->x) / 30] == 'E')
			return 1 ;
		if (dt.fe == 0 && vars->map[(vars->y - 30) / 30 ][(vars->x) / 30] == 'E')
			exit(1) ;
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars);
		vars->y -= 30;
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		printf("moves : %d\n",vars->moves);
	}
	if (keycode == 1 && vars->map[(vars->y + 30) / 30 ][(vars->x) / 30] != '1')
	{
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		if (dt.fe == -1 && vars->map[(vars->y + 30) / 30 ][(vars->x) / 30] == 'E')
			return 1 ;
		if (dt.fe == 0 && vars->map[(vars->y + 30) / 30 ][(vars->x) / 30] == 'E')
			exit(1) ;
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars);
		vars->y += 30;
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		printf("moves : %d\n",vars->moves);
	}
	return (0);
}
