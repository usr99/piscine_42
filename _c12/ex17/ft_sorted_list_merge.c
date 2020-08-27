/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 22:01:31 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 02:25:33 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*ptr;

	ptr = *begin_list1;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = begin_list2;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list_ptr;
	void	*ptr_data;
	void	*ptr_next_data;

	list_ptr = *begin_list;
	while (list_ptr->next)
	{
		ptr_data = list_ptr->data;
		ptr_next_data = list_ptr->next->data;
		if ((*cmp)(ptr_data, ptr_next_data) > 0)
		{
			list_ptr->data = ptr_next_data;
			list_ptr->next->data = ptr_data;
			list_ptr = *begin_list;
		}
		else
			list_ptr = list_ptr->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
