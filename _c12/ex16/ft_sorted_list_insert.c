/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:47:16 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 02:30:03 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

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

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*ptr;
	t_list	*prev;
	t_list	*new;

	ptr = *begin_list;
	prev = NULL;
	while (ptr && (*cmp)(ptr->data, data) < 0)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	new = ft_create_elem(data);
	if (!prev)
		*begin_list = new;
	else
		prev->next = new;
	new->next = ptr;
}
