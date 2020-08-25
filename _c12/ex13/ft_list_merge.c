/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user_99 <mael.91150@hotmail.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 04:55:56 by user_99           #+#    #+#             */
/*   Updated: 2020/08/25 04:58:42 by user_99          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
    t_list  *ptr;

    ptr = *begin_list1;
    while (ptr->next)
	ptr = ptr->next;
    ptr->next = begin_list2;
}
