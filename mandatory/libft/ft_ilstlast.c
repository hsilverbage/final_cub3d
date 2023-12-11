#include "libft.h"

t_ilst	*ft_ilstlast(t_ilst *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
