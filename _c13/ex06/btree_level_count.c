/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 08:41:20 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 09:24:57 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	count_tree_level(t_btree *root, int level, int max_level)
{
	int	new_max;

	if (!root)
		return (level);
	level++;
	if ((new_max = count_tree_level(root->left, level, max_level)) > level)
		max_level = new_max;
	if ((new_max = count_tree_level(root->right, level, max_level)) > level)
		max_level = new_max;
	if (level == 1)
		return (max_level);
	return (level);
}

int	btree_level_count(t_btree *root)
{
	return (count_tree_level(root, 0, 0));
}
