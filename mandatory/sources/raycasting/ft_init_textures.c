#include "cub3D.h"

int	ft_create_img(t_game *game, char *path, int side)
{
	int		height;
	int		width;
	t_img	img;

	img.img = mlx_xpm_file_to_image(game->mlx->mlx, path, &width, &height);
	if (!img.img)
	{
		printf("Can't open texture : "\
			"%d\n0 : NO\n1 : SO\n2 : WE\n3 : EA\n", side);
		ft_exit(game);
		return (1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	game->texture[side] = img;
	return (0);
}

static void	ft_free_tab(t_game *game, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(game->mlx->mlx, game->texture[i].img);
		i--;
	}
}

int	ft_init_textures(t_game *game)
{
	if (ft_create_img(game, game->north, NORTH))
		return (1);
	if (ft_create_img(game, game->south, SOUTH))
		return (ft_free_tab(game, 0), 1);
	if (ft_create_img(game, game->west, WEST))
		return (ft_free_tab(game, 1), 1);
	if (ft_create_img(game, game->east, EAST))
		return (ft_free_tab(game, 2), 1);
	return (0);
}
