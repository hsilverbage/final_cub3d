/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmedkhelladipro <ahmedkhelladipro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:49:26 by ahmedkhella       #+#    #+#             */
/*   Updated: 2023/12/10 16:32:50 by ahmedkhella      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_error_msg(char *str, t_game *game)
{
	(void) game;
	ft_free_all(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	exit (EXIT_FAILURE);
}

void	ft_perror_exit(void)
{
	perror("Error ");
	exit(EXIT_FAILURE);
}
