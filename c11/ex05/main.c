/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 01:52:21 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/19 03:04:49 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_operator.h"
#include "ft_fct.h"

int		ft_which_operator(char *operator)
{
	if (operator[1] != '\0')
		return (-1);
	if (*operator == '+')
		return (0);
	if (*operator == '-')
		return (1);
	if (*operator == '*')
		return (2);
	if (*operator == '/')
		return (3);
	if (*operator == '%')
		return (4);
	return (-1);
}

void	ft_do_op(int val1, int val2, int id_operator)
{
	int	(*tab_functions[5])(int, int);
	int res;

	tab_functions[0] = &ft_add;
	tab_functions[1] = &ft_substract;
	tab_functions[2] = &ft_multiply;
	tab_functions[3] = &ft_divide;
	tab_functions[4] = &ft_modulo;
	res = (*tab_functions[id_operator])(val1, val2);
	ft_putnbr(res);
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int	id_operator;
	int	val1;
	int	val2;

	if (argc != 4)
		return (0);
	if ((id_operator = ft_which_operator(argv[2])) == -1)
	{
		ft_putstr("0\n");
		return (0);
	}
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	if (id_operator == 3 && val2 == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (id_operator == 4 && val2 == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	ft_do_op(val1, val2, id_operator);
	return (0);
}
