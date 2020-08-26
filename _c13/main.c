/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:28:10 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 07:38:21 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item);
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

void	aff_tree(t_btree *root)
{
	char	*str;

	if (!root)
		return ;
	str = root->item;
	printf("%s\n", str);
	if (root->left)
		aff_tree(root->left);
	if (root->right)
		aff_tree(root->right);
}

int	main(int ac, char **av)
{
	int		i;
	t_btree	*root;

	i = 2;
	root = btree_create_node(av[1]);
	while (i < ac)
	{
		btree_insert_data(&root, av[i], &strcmp);
		i++;
	}
	aff_tree(root);
	return (0);
}
