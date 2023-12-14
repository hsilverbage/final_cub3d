/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:56:29 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/14 23:05:55 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

static void	ft_set_direction(t_game *game, double dir_x, double dir_y)
{
	game->ray->dir.x = dir_x;
	game->ray->dir.y = dir_y;
}

static void	ft_set_plane(t_game *game, double plane_x, double plane_y)
{
	game->ray->plane.x = plane_x;
	game->ray->plane.y = plane_y;
}

static void	ft_init_direction(t_game *game, char c)
{
	if (c == 'N')
	{
		ft_set_direction(game, -1, 0);
		ft_set_plane(game, 0, 0.60);
	}
	else if (c == 'S')
	{
		ft_set_direction(game, 1, 0);
		ft_set_plane(game, 0, -0.60);
	}
	else if (c == 'E')
	{
		ft_set_direction(game, 0, 1);
		ft_set_plane(game, 0.60, 0);
	}
	else if (c == 'W')
	{
		ft_set_direction(game, 0, -1);
		ft_set_plane(game, -0.60, 0);
	}
}

void	ft_init_ray(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		ft_error_msg(ERR_MALLOC, game);
	ft_reset_ray(game->ray);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_isalpha(game->map[i][j]))
			{
				ft_init_direction(game, game->map[i][j]);
				game->ray->pos.x = i + 0.5;
				game->ray->pos.y = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}
