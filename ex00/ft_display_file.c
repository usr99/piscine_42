/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:16:33 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/17 05:26:37 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_read_file(int fd)
{
	char	buffer;

	while (read(fd, &buffer, 1))
	{
		ft_putstr(1, &buffer);
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
	{
		ft_putstr(2, "File name missing.\n");
		return (-1);
	}
	else if (argc > 2)
	{
		ft_putstr(2, "Too many arguments.\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, "Cannot read file.\n");
		return (-1);
	}
	ft_read_file(fd);
	return (0);
}
