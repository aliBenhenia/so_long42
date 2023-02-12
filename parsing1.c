#include "so_long.h"

void	countHeight(char *s, t_long *data)
{
	int	i;
	int	fd;
	char	*line;

	fd = open(s,O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break;
	}
	free(line);
	close(fd);
}
void	fill_map(char *s, t_long *data)
{
	int	fd;
	int	i;
	char *line;

	fd = open(s,O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	data->map = (char**) malloc(data->height * sizeof(char*));
	while (line)
	{
		// data->map[i] = (char*) malloc(10 * sizeof(char));
		// strcpy(data->map[i],line);
		data->map[i] = line;
		i++;
		line = get_next_line(fd);
		// free(line);
	}
	close(i);
}
int	count_line_collect(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s == NULL)
	{
		return 0;
	}
	
	while (s[i])
	{
		if (s[i] == 'C')
			j++;
		i++;
	}
	return (j);
}
void	countCollect(char *s, t_long *data)
{
	int	fd;
	char *line;

	fd = open(s,O_RDONLY);
	line = get_next_line(fd);
	
	while (line)
	{
		
		data->coins += count_line_collect(line);
		free(line);
		line = get_next_line(fd);
	}
}


void	parsing(char *s,t_long *data)
{
	check_extention(s);
	check_arrounded(s);
    check_wall_row(s);
	check_characters(s);
	check_rectangle(s);
	check_correct_char(s);
	countWidth(s,data);
	countHeight(s,data);
	countCollect(s, data);
	fill_map(s,data);
	
}
