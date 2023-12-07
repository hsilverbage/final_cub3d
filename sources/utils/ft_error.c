#include "cub3D.h"

void	ft_error_msg(char *str, t_game *game)
{
	(void) game;
	// ft_free_all(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit (EXIT_FAILURE);
}

void	ft_perror_exit(void)
{
	perror("Error ");
	exit(EXIT_FAILURE);
}
