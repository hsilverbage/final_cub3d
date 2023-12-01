#include "cub3D.h"

static void	ft_check_extension(char *str, t_game *game)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'b' && str[i - 2] == 'u'
			&& str[i - 3] == 'c' && str[i - 4] == '.'))
	{
		ft_error_msg("Invalid map extension !", game);
	}
}

static int	ft_count_lines(char *file, t_game *game)
{
	char	*line;
	int		fd;
	int		nb_lines;

	nb_lines = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror_exit();
	line = get_next_line(fd);
	while (line)
	{
		nb_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!nb_lines)
		ft_error_msg(".cub file is empty", game);
	return (nb_lines);
}

static void	ft_get_file(char *file, int nb_lines, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror_exit();
	game->file = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->file)
		ft_error_msg("ERR_MALLOC", game);
	line = get_next_line(fd);
	while (line)
	{
		game->file[i++] = line;
		line = get_next_line(fd);
	}
	game->file[i] = NULL;
	close(fd);
}

void	ft_parsing(t_game *game, char *file)
{
	int	nb_lines;
	int	start_map1;
	int	start_map2;

	nb_lines = ft_count_lines(file, game);
	ft_check_extension(file, game);
	ft_get_file(file, nb_lines, game);
	start_map1 = ft_get_textures(game->file, game);
	start_map2 = ft_get_colors(game);
	ft_check_textures(game);
	if (start_map1 > start_map2)
		game->map = game->file + start_map1;
	else
		game->map = game->file + start_map2;
	ft_parse_map(game);
	// int i = 0;
	// while (game->map[i])
	// 	printf("%s\n", game->map[i++]);
	// printf("%s\n", game->north);
	// printf("%s\n", game->south);
	// printf("%s\n", game->east);
	// printf("%s\n", game->west);
	// printf("%s\n", game->floor);
	// printf("%s\n", game->ceiling);
}
