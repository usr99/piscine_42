/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:00:39 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/25 04:54:36 by user_99          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), 
		void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*list_previous;
	t_list	*list_remove;

	list_ptr = *begin_list;
	list_previous = NULL;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if (list_previous == NULL)
			    *begin_list = list_ptr->next;
			else
			    list_previous->next = list_ptr->next;
			list_remove = list_ptr;
			list_ptr = list_ptr->next;
			(*free_fct)(list_remove->data);
			free(list_remove);
		}
		else
		{
			list_previous = list_ptr;
			list_ptr = list_ptr->next;
		}
	}
}
