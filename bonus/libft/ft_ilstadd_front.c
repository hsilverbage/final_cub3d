#include "libft.h"

void	ft_ilstadd_front(t_ilst **lst, t_ilst *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
