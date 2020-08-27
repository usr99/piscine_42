/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:21:45 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/25 19:21:58 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

void	ft_puterror(char *file_name, char *program_name)
{
	ft_putstr(basename(program_name), 2);
	ft_putstr(": ", 2);
	ft_putstr(file_name, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	ft_putstr("\n", 2);
}

void	ft_read_file(int fd, int offset)
{
	char	*file_content;
	char	buffer;
	int		file_size;
	int		bytes_read;

	file_size = 0;
	file_content = malloc(sizeof(char) * (offset + 1));
	if (!file_content)
		return ;
	ft_clear_file_content(file_content, offset);
	while ((bytes_read = read(fd, &buffer, 1)))
	{
		file_size += bytes_read;
		ft_save_file_content(file_content, buffer, offset);
	}
	if (offset > file_size)
		write(1, file_content + offset - file_size, file_size);
	else
		write(1, file_content, offset);
	close(fd);
	free(file_content);
}

void	ft_tail(int offset, char **name, int argc)
{
	int		fd;
	int		i;
	int		is_first_file;

	i = 2;
	is_first_file = 1;
	while (i++ < argc)
	{
		while ((fd = open(name[i], O_RDONLY)) == -1 && i < argc)
		{
			ft_puterror(name[i], name[0]);
			i++;
		}
		if (argc > 4 && i < argc)
		{
			if (!is_first_file)
				ft_putstr("\n", 1);
			ft_putstr("==> ", 1);
			ft_putstr(name[i], 1);
			ft_putstr(" <==\n", 1);
			is_first_file = 0;
		}
		if (fd != -1)
			ft_read_file(fd, offset);
	}
}

void	ft_loop(int offset)
{
	char	*file_content;
	char	buffer;
	int		file_size;
	int		bytes_read;

	file_size = 0;
	file_content = malloc(sizeof(char) * (offset + 1));
	if (!file_content)
		return ;
	ft_clear_file_content(file_content, offset);
	while ((bytes_read = read(0, &buffer, 1)))
	{
		file_size += bytes_read;
		ft_save_file_content(file_content, buffer, offset);
	}
	if (offset > file_size)
		write(1, file_content + offset - file_size, file_size);
	else
		write(1, file_content, offset);
	free(file_content);
}

int		main(int argc, char **argv)
{
	int	tail_size;

	if (argc == 2)
	{
		ft_putstr(basename(argv[0]), 2);
		ft_putstr(": option requires an argument -- c\nusage: ", 2);
		ft_putstr(basename(argv[0]), 2);
		ft_putstr(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n", 2);
	}
	else if ((tail_size = ft_atoi(argv[2])) == -1)
	{
		ft_putstr(basename(argv[0]), 2);
		ft_putstr(": illegal offset -- ", 2);
		ft_putstr(argv[2], 2);
		ft_putstr("\n", 2);
	}
	else if (tail_size >= 0 && argc == 3)
		ft_loop(tail_size);
	else
		ft_tail(tail_size, argv, argc);
	return (0);
}
