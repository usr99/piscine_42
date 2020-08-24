#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

void	aff_list(t_list *begin)
{
	while (begin)
	{
		printf("%s\n", begin->data);
		begin = begin->next;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list *new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
		return (NULL);
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

t_list	*ft_list_last(t_list *begin_list)
{
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*last_elem;

	new_elem = ft_create_elem(data);
	last_elem = ft_list_last(*begin_list);
	last_elem->next = new_elem;
}

int		main(int argc, char **argv)
{
	int		i;
	t_list	*begin;

	i = 2;
	begin = ft_create_elem(argv[1]);
	while (i < argc)
	{
		ft_list_push_back(&begin, argv[i]);
		i++;
	}
	aff_list(begin);
	return (0);
}
