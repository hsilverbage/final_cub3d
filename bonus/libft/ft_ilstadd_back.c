#include "libft.h"

void	ft_ilstadd_back(t_ilst **lst, t_ilst *new)
{
	t_ilst	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_ilstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
