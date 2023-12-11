#include "libft.h"

int	ft_ilstsize(t_ilst *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
