#include "so_long.h"
void	move_handle1(int keycode, t_long *vars,t_help *dt)
{
	if (dt->fe == -1 && vars->map[vars->y / 30 ][(vars->x - 30) / 30] == 'E')
			return ;
		if (dt->fe == 0 && vars->map[vars->y / 30 ][(vars->x - 30) / 30] == 'E')
			exit(1) ;
		vars->x -= 30;
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->coins--;
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
		}
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars,dt);
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		ft_putstr("moves : ");
		ft_putnbr_fd(vars->moves,1);
		ft_putstr("\n");
}
void	move_handle2(int keycode, t_long *vars,t_help *dt)
{
	if (dt->fe == -1 && vars->map[vars->y / 30 ][(vars->x + 30) / 30] == 'E')
			return ;
		if (dt->fe == 0 && vars->map[vars->y / 30 ][(vars->x + 30) / 30] == 'E')
			exit(1) ;
		vars->x += 30;
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars, dt);
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		ft_putstr("moves : ");
		ft_putnbr_fd(vars->moves,1);
		ft_putstr("\n");
}
void	move_handle3(int keycode, t_long *vars,t_help *dt)
{
	if (dt->fe == -1 && vars->map[(vars->y - 30) / 30 ][(vars->x) / 30] == 'E')
			return ;
		if (dt->fe == 0 && vars->map[(vars->y - 30) / 30 ][(vars->x) / 30] == 'E')
			exit(1);
		vars->y -= 30;
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars,dt);
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		ft_putstr("moves : ");
		ft_putnbr_fd(vars->moves,1);
		ft_putstr("\n");
}
void	move_handle4(int keycode, t_long *vars,t_help *dt)
{
	if (dt->fe == -1 && vars->map[(vars->y + 30) / 30 ][(vars->x) / 30] == 'E')
			return  ;
		if (dt->fe == 0 && vars->map[(vars->y + 30) / 30 ][(vars->x) / 30] == 'E')
			exit(1) ;
		vars->y += 30;
		if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'C')
		{
			vars->map[vars->y / 30 ][(vars->x) / 30] = '0';
			vars->coins--;
		}
		mlx_clear_window(vars->mlx, vars->wind);
		render_map(vars, dt);
		mlx_put_image_to_window(vars->mlx, vars->wind , vars->img[2], vars->x , vars->y);
		vars->moves++;
		ft_putstr("moves : ");
		ft_putnbr_fd(vars->moves,1);
		ft_putstr("\n");
}
int	move(int keycode,t_long *vars,t_help *dt)
{
	if (keycode == 53) 
	{
		exit(0);
	}
	// dt->fe = -1;
	if (vars->coins == 0)
		dt->fe = 0;
	if (vars->map[vars->y / 30 ][(vars->x) / 30] == 'E' && vars->coins == 0)
	{
		ft_free(vars->map);
		exit(0);
	 }
	if (keycode == 0 && vars->map[vars->y / 30 ][(vars->x - 30) / 30] != '1')
		move_handle1(keycode,vars,dt);
	if (keycode == 2 && vars->map[vars->y / 30 ][(vars->x + 30) / 30] != '1')
		move_handle2(keycode,vars,dt);
	if (keycode == 13 && vars->map[(vars->y - 30) / 30 ][(vars->x) / 30] != '1')
		move_handle3(keycode,vars,dt);
	if (keycode == 1 && vars->map[(vars->y + 30) / 30 ][(vars->x) / 30] != '1')
		move_handle4(keycode,vars,dt);
	return (0);
}
