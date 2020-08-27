/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:14:12 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/25 19:14:45 by mamartin         ###   ########.fr       */
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

int		ft_read_file(char *filename)
{
	int		fd;
	int		nb_bytes_read;
	char	buffer[4097];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, "Cannot read file.\n");
		return (-1);
	}
	while ((nb_bytes_read = read(fd, buffer, 4096)))
		write(1, buffer, nb_bytes_read);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
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
	return (ft_read_file(argv[1]));
}
