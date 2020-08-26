/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:55:23 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 08:35:34 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*item;

	if (!root)
		return (0);
	if ((item = btree_search_item(root->left, data_ref, cmpf)) != 0)
		return (item);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	if ((item = btree_search_item(root->right, data_ref, cmpf)) != 0)
		return (item);
	return (0);
}
