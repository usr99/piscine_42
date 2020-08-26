/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:53:03 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 02:29:38 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*ptr;
	void	*sw;
	int		i;
	int		size_list;

	size_list = 0;
	ptr = begin_list;
	while (ptr)
	{
		ptr = ptr->next;
		size_list++;
	}
	while (size_list--)
	{
		i = 0;
		ptr = begin_list;
		while (i < size_list)
		{
			sw = ptr->data;
			ptr->data = ptr->next->data;
			ptr->next->data = sw;
			ptr = ptr->next;
			i++;
		}
	}
}
