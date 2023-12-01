#include "cub3D.h"

static char	*ft_extract_path(char *str, char c1, char c2, t_game *game)
{
	int	i;
	int	fd;
	int	stop;

	i = 0;
	stop = 0;
	while (stop < 3 && \
		(str[i] == c1 || str[i] == c2 || str[i] == ' ' || str[i] == '\t'))
	{
		if (str[i] == c1 || str[i] == c2)
			stop++;
		i++;
	}
	fd = open(str + i, O_RDONLY);
	if (fd < 0)
	{
		printf("Error : Impossible to access %c%c path\n", c1, c2);
		ft_free_all(game);
		perror(NULL);
		exit (EXIT_FAILURE);
	}
	close(fd);
	return (str + i);
}

int	ft_get_textures(char **file, t_game *game)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (file[i])
	{
		while (file[i][y] == ' ')
			y++;
		if (ft_valid_tex_char(file[i][y]) == false)
			break ;
		if (!ft_strncmp(file[i] + y, "NO", 2) && ft_double(game->north, game))
			game->north = ft_extract_path(file[i], 'N', 'O', game);
		if (!ft_strncmp(file[i] + y, "SO", 2) && ft_double(game->south, game))
			game->south = ft_extract_path(file[i], 'S', 'O', game);
		if (!ft_strncmp(file[i] + y, "WE", 2) && ft_double(game->west, game))
			game->west = ft_extract_path(file[i], 'W', 'E', game);
		if (!ft_strncmp(file[i] + y, "EA", 2) && ft_double(game->east, game))
			game->east = ft_extract_path(file[i], 'E', 'A', game);
		i++;
		y = 0;
	}
	return (i);
}
