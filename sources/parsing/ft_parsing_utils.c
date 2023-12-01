#include "cub3D.h"

bool	ft_valid_tex_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == 'F' || \
		c == 'C' || c == '\0')
	{
		return (true);
	}
	return (false);
}

bool	ft_double(char *str, t_game *game)
{
	if (!str)
		return (true);
	ft_error_msg("Same texture or color found twice in .cub file !", game);
	return (false);
}

void	ft_check_textures(t_game *game)
{
	if (!game->north)
		ft_error_msg(NO_ERR, game);
	if (!game->south)
		ft_error_msg(SO_ERR, game);
	if (!game->west)
		ft_error_msg(WE_ERR, game);
	if (!game->east)
		ft_error_msg(EA_ERR, game);
	if (!game->ceiling)
		ft_error_msg(C_ERR, game);
	if (!game->floor)
		ft_error_msg(F_ERR, game);
}
