/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:28:11 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 02:24:54 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
