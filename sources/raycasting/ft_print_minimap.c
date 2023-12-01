#include "cub3D.h"

static void	ft_add_background(t_img *img)
{
	int	x;
	int	y;
	int	dx;
	int	dy;

	x = 0;
	while (x < (P_OFFSET + 10) * 2)
	{
		dx = abs(x - P_OFFSET);
		y = 0;
		while (y < (P_OFFSET + 10) * 2)
		{
			dy = abs(y - P_OFFSET);
			if (sqrt(dx * dx + dy * dy) < 150)
				ft_mlx_pixel_put(img, x, y, 0);
			y++;
		}
		x++;
	}
}

static double	ft_get_angle(t_game *game)
{
	double	angle;

	if (game->ray->dir.y >= 0)
		angle = acos(game->ray->dir.x);
	else
		angle = (2 * M_PI) - acos(game->ray->dir.x);
	angle = M_PI - angle;
	return (angle);
}

static void	ft_choose_color(t_game *game, t_point p, t_img *img, double angle)
{
	if (game->map[img->y][img->x] == '1')
		ft_put_square(game, p, 0xFFFFFF, angle);
	else
		ft_put_square(game, p, game->floor_color, angle);
}

static void	ft_put_player(t_img *img, int color)
{
	int	x;
	int	y;

	x = P_OFFSET - 2;
	while (x <= P_OFFSET + 2)
	{
		y = P_OFFSET - 2;
		while (y <= P_OFFSET + 2)
			ft_mlx_pixel_put(img, x, y++, color);
		x++;
	}
}

void	ft_print_minimap(t_game *game, t_img *img)
{
	t_point	p;
	double	angle;

	angle = ft_get_angle(game);
	ft_add_background(img);
	img->y = -1;
	while (game->map[++img->y])
	{
		img->x = -1;
		while (game->map[img->y][++img->x])
		{
			p.x = img->x * CUB_SIZE;
			p.y = img->y * CUB_SIZE;
			ft_choose_color(game, p, img, angle);
		}
	}
	game->mlx->img.y = game->ray->pos.x - 1;
	game->mlx->img.x = game->ray->pos.y - 1;
	ft_put_player(img, 0x00002A);
}
