/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:57:05 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/22 19:24:07 by mamartin         ###   ########.fr       */
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

void	ft_list_push(t_list *last_elem, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_elem(data);
	last_elem->next = new_elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*begin;
	int		i;

	i = 1;
	if (size < 1)
		return (NULL);
	list = ft_create_elem(strs[0]);
	begin = list;
	while (i < size)
	{
		ft_list_push(list, strs[i]);
		list = list->next;
		i++;
	}
	return (begin);
}
