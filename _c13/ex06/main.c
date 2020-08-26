/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 07:28:10 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/26 09:20:19 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_btree.h"

int	btree_level_count(t_btree *root);

t_btree	*btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (*root == NULL)
	{
		*root = btree_create_node(item);
		return ;
	}
	if ((*cmpf)((*root)->item, item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}

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
	printf("\n\n%d", btree_level_count(root));
	return (0);
}
