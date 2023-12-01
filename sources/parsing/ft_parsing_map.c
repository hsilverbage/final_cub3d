#include "cub3D.h"

void	ft_parse_map(t_game *game)
{
	int		i;

	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}
// static int	ft_parse_map(t_game *game)
// {
// 	if (!ft_is_valid_map(game))
// 		return (ft_free_list(game->map_list), ft_free_struct(game), \
// 			ft_error(10));
// 	if (ft_check_walls(game))
// 		return (ft_free_str(game->map), ft_free_struct(game), 1);
// 	return (0);
// }

// static int	ft_is_valid_char(char c)
// {
// 	char	*charset;

// 	charset = " 012356NSEW";
// 	while (*charset)
// 		if (*charset++ == c)
// 			return (1);
// 	return (0);
// }

// static int	ft_get_alpha(t_ilst *current, int alpha)
// {
// 	while (current)
// 	{
// 		if (!ft_is_valid_char((char)current->content))
// 			return (-1);
// 		if (ft_isalpha((char)current->content))
// 			alpha++;
// 		current = current->next;
// 	}
// 	return (alpha);
// }

// int	ft_is_valid_map(t_game *game)
// {
// 	t_list	*list;
// 	int		alpha;

// 	alpha = 0;
// 	list = game->map_list;
// 	while (list)
// 	{
// 		alpha = ft_get_alpha(list->content, alpha);
// 		if (alpha == -1)
// 			return (0);
// 		list = list->next;
// 	}
// 	if (alpha > 1 || alpha == 0)
// 		return (0);
// 	return (1);
// }

// static int	ft_is_wall(char c)
// {
// 	if (c == '1' || c == '2')
// 		return (1);
// 	return (0);
// }

// static int	ft_check_void(t_game *game, int i, int j)
// {
// 	int	width;
// 	int	height;

// 	width = ft_strlen(game->map[i]) - 1;
// 	height = 0;
// 	while (game->map[height])
// 		height++;
// 	if (i < height - 1 && !ft_is_wall(game->map[i + 1][j]))
// 		return (1);
// 	if (i > 0 && !ft_is_wall(game->map[i - 1][j]))
// 		return (1);
// 	if (j < width && !ft_is_wall(game->map[i][j + 1]))
// 		return (1);
// 	if (j > 0 && !ft_is_wall(game->map[i][j - 1]))
// 		return (1);
// 	return (0);
// }

// int	ft_check_walls(t_game *game)
// {
// 	int	i;
// 	int	j;
// 	int	width;
// 	int	height;

// 	width = ft_strlen(game->map[0]) - 1;
// 	height = 0;
// 	while (game->map[height])
// 		height++;
// 	i = -1;
// 	while (game->map[++i])
// 	{
// 		j = -1;
// 		while (game->map[i][++j])
// 		{
// 			if (game->map[i][j] == '2' && ft_check_void(game, i, j))
// 				return (ft_error(7));
// 			if ((i == 0 || i == height - 1) && !ft_is_wall(game->map[i][j]))
// 				return (ft_error(7));
// 			if ((j == 0 || j == width) && !ft_is_wall(game->map[i][j]))
// 				return (ft_error(7));
// 		}
// 	}
// 	return (0);
// }
