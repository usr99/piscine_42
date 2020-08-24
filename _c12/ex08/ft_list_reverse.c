/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 22:36:51 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/23 00:56:03 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*save_previous;
	t_list	*save_next;
	t_list	*list;

	list = *begin_list;
	save_previous = 0;
	while (list)
	{
		save_next = list->next;
		list->next = save_previous;
		save_previous = list;
		list = save_next;
	}
	*begin_list = save_previous;
}
