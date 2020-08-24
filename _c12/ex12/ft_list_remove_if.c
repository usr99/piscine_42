/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:00:39 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/24 14:51:27 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), 
		void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*list_previous;
	t_list	*list_next;

	list_ptr = *begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if ()
			list_previous->next = list_ptr->next;
			(*free_fct)(list_ptr->data);
			free(list_ptr);
			list_ptr = list_previous->next;
		}
		else
		{
			list_previous = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
}
