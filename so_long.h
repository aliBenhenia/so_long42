#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>
# include<fcntl.h>
# include<string.h>
#include "./get_next_line42/get_next_line.h"
typedef struct t_long
{
    void    *mlx; 
    void    *wind;
    void    **pic;
    void    **img;
    void    **paths;
    char    **map;
    void    *wall;
    void    *player;
    int     width;
    int     height;
    int     x;
    int     y;
    int     coins;
    int     moves;
}t_long;

typedef struct t_help{
    int fx;
    int fy;
    int fe;
}t_help;
t_help dt;
void	ft_error(char *s);
void	parsing(char *s,t_long *data);
void	check_extention(char *s);
void	check_arrounded(char *s);
int	line_contain(char *s, char c);
void	check_characters(char *s);
void	check_rectangle(char *s);
void	check_correct_char(char *s);
void	countWidth(char *s, t_long *data);
void	render_map(t_long *data);
int	move(int keycode, t_long *vars);
void    check_wall_row(char *s);
void	ft_free(char *p[]);