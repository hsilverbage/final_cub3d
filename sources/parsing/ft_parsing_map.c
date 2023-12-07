#include "cub3D.h"

static void	ft_check_valid_map_char(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (ft_valid_map_char(game->map[y][x]) == false)
				ft_error_msg("Invalid char found in map", game);
			x++;
		}
		y++;
		x = 0;
	}
}

static void ft_init_start_pos(t_game *game)
{
	int	x;
	int	y;
	int	set;

	x = 0;
	y = 0;
	set = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (ft_valid_start_char(game->map[y][x]) == true)
			{
				game->
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_parse_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
	ft_check_valid_map_char(game);
}
