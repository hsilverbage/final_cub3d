/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:52:48 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/14 23:05:55 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3Dbonus.h"

void	ft_rot_left(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->ray->dir.x;
	game->ray->dir.x = game->ray->dir.x * cos(ROT_SPEED) - \
		game->ray->dir.y * sin(ROT_SPEED);
	game->ray->dir.y = olddir_x * sin(ROT_SPEED) + \
		game->ray->dir.y * cos(ROT_SPEED);
	oldplane_x = game->ray->plane.x;
	game->ray->plane.x = game->ray->plane.x * cos(ROT_SPEED) \
		- game->ray->plane.y * sin(ROT_SPEED);
	game->ray->plane.y = oldplane_x * sin(ROT_SPEED) \
		+ game->ray->plane.y * cos(ROT_SPEED);
}

void	ft_rot_right(t_game *game)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = game->ray->dir.x;
	game->ray->dir.x = game->ray->dir.x * cos(-ROT_SPEED) \
		- game->ray->dir.y * sin(-ROT_SPEED);
	game->ray->dir.y = olddir_x * sin(-ROT_SPEED) \
		+ game->ray->dir.y * cos(-ROT_SPEED);
	oldplane_x = game->ray->plane.x;
	game->ray->plane.x = game->ray->plane.x * cos(-ROT_SPEED) \
		- game->ray->plane.y * sin(-ROT_SPEED);
	game->ray->plane.y = oldplane_x * sin(-ROT_SPEED) \
		+ game->ray->plane.y * cos(-ROT_SPEED);
}
