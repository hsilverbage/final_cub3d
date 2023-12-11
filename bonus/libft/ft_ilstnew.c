#include "libft.h"

t_ilst	*ft_ilstnew(int content)
{
	t_ilst	*ptr;

	ptr = malloc(sizeof(t_ilst));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
