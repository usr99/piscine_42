/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 05:16:33 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/23 19:49:06 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_read_file.h"

void	ft_puterror(char *file_name, char *program_name)
{
	ft_putstr(basename(program_name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

void	ft_cat(char *file_name, char *program_name)
{
	int	fd;

	if ((fd = open(file_name, O_DIRECTORY)) == -1)
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
		{
			ft_puterror(file_name, program_name);
			return ;
		}
		ft_read_file(fd);
		close(fd);
	}
	else
	{
		errno = EISDIR;
		ft_puterror(file_name, program_name);
	}
}

void	ft_read_input(void)
{
	char	buffer;

	while (read(0, &buffer, 1))
		write(1, &buffer, 1);
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1 || argv[1][0] == '-')
		ft_read_input();
	else
	{
		while (i < argc)
		{
			ft_cat(argv[i], argv[0]);
			i++;
		}
	}
	return (0);
}
