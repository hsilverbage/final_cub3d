#include "cub3D.h"

static t_point	ft_rotate_point(t_point p, double angle)
{
	t_point	new_point;
	int		xm;
	int		ym;

	xm = p.x - P_OFFSET;
	ym = p.y - P_OFFSET;
	new_point.x = xm * cos(angle) + ym * sin(angle) + P_OFFSET;
	new_point.y = -xm * sin(angle) + ym * cos(angle) + P_OFFSET;
	return (new_point);
}

void	ft_put_square(t_game *game, t_point p, int color, double angle)
{
	int		i;
	t_point	p1;
	t_point	p2;

	i = 0;
	if (p.x < 0 || p.y < 0)
		return ;
	while (i < CUB_SIZE)
	{
		p1.x = P_OFFSET + p.x + i - game->ray->pos.y * CUB_SIZE;
		p1.y = P_OFFSET + p.y - game->ray->pos.x * CUB_SIZE;
		p2.x = P_OFFSET + p.x + i - game->ray->pos.y * CUB_SIZE;
		p2.y = P_OFFSET + p.y + CUB_SIZE - game->ray->pos.x * CUB_SIZE;
		ft_print_line(game, ft_rotate_point(p1, angle), \
			ft_rotate_point(p2, angle), color);
		i++;
	}
}
