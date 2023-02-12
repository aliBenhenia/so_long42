#include "so_long.h"
int	containe_other(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'C' 
			&& s[i] != 'E' && s[i] != 'P' && s[i] != '\n' && s[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}
void	check_correct_char(char *s)
{
	int	i;
	char	*line;

	i = open(s,O_RDONLY);
	line = get_next_line(i);
	while (line)
	{
		if (containe_other(line))
			ft_error("other character\n");
		free(line);
		line = get_next_line(i);
	}
}
void	countWidth(char *s, t_long *data)
{
	int	i;
	int	fd;
	char	*line;

	fd = open(s,O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line[i] && line[i++] != '\n')
		data->width++;
	free(line);
	close(fd);
}
void    check_wall_row(char *s)
{
    int	i;
    int	j;
	char	*line;
	char	*t;

	i = open(s,O_RDONLY);
    j = 0;
	line = get_next_line(i);
    while (line[j] != '\0' && line[j] != '\n')
    {
        if (line[j] != '1')
            ft_error("should all be walls");
        j++;
    }
	free(line);
    j = 0;
    t = malloc(sizeof(char*) * strlen(line));
    while (line)
    {
        strcpy(t,line);
        line = get_next_line(i);
        if (line == NULL)
        {
            while (t[j] != '\0' && t[j] != '\n')
            {
                if (t[j] != '1')
                    ft_error("should all be walls\n");
                j++;
            }
        }
        free(line);
    }
    free(line);
    free(t);
}