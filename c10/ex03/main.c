/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 03:05:17 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/27 19:11:50 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fct.h"

int		ft_open_file(char *file, char *program, int is_bad_fd)
{
	int	fd;

	if ((fd = open(file, O_DIRECTORY)) == -1)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
		{
			ft_puterror(program, file);
			if (is_bad_fd)
			{
				errno = 9;
				ft_puterror(program, file);
			}
			return (0);
		}
		else
			return (fd);
	}
	else
	{
		errno = 21;
		ft_puterror(program, file);
		return (0);
	}
}

char	*ft_hexdump(int fd, char *buffer, int *offset, int *len)
{
	int		ret;
	char	*last_buffer;

	last_buffer = NULL;
	while ((ret = read(fd, buffer + *len, 16 - *len)) == 16 - *len)
	{
		*len = 0;
		if (ft_cmpbuf(last_buffer, buffer, len) == 1)
		{
			ft_putstr("*\n", 1);
			*offset += 16;
			while ((ret = read(fd, buffer + *len, 16 - *len)) == 16 - *len
					&& ft_cmpbuf(last_buffer, buffer, len) == 1)
				*offset += 16;
			ft_print_line(offset, buffer, buffer[16], len);
		}
		else
			ft_print_line(offset, buffer, buffer[16], len);
		last_buffer = ft_dupbuf(buffer, len);
	}
	*len = ret;
	free(last_buffer);
	return (buffer);
}

void	ft_loop_files(char **av, int ac, int is_c, char *program_name)
{
	int		is_valid;
	int		fd;
	int		offset;
	int		len;
	char	*buffer;

	offset = 0;
	is_valid = 0;
	if (!(buffer = malloc(sizeof(char) * 17)))
		return ;
	ft_init_buffer(buffer, is_c, &len);
	av += 1 + is_c;
	while (ac > 1 + is_c)
	{
		if ((fd = ft_open_file(*av, program_name, bad_fd(is_c, ac, is_valid))))
		{
			buffer = ft_hexdump(fd, buffer, &offset, &len);
			is_valid = 1;
		}
		if (ac == 2 + is_c && is_valid)
			ft_print_last_line(buffer, offset, is_c, &len);
		ac--;
		av++;
	}
	free(buffer);
}

void	ft_hexdump_input(int is_c, int ret, int *offset, int len)
{
	char	*buffer;
	char	*last_buffer;

	last_buffer = NULL;
	buffer = malloc(sizeof(char) * 16);
	while ((ret = read(0, buffer + len, 16 - len)))
	{
		if (ret >= 16 - len)
		{
			len = 0;
			if (ft_cmpbuf(last_buffer, buffer, &len) == 1)
				ft_same_lines(last_buffer, buffer, &len, offset);
			else
				ft_print_line(offset, buffer, is_c, &len);
			last_buffer = ft_dupbuf(buffer, &len);
		}
		else
			ft_term_buf(&len, ret);
	}
	if (last_buffer != NULL)
		ft_print_last_line(buffer, *offset, is_c, &len);
	free_buf(buffer, last_buffer);
}

int		main(int argc, char **argv)
{
	int	offset;

	offset = 0;
	if (argc == 1)
		ft_hexdump_input(0, 0, &offset, 0);
	else if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-C") == 0)
			ft_hexdump_input(1, 0, &offset, 0);
		else
			ft_loop_files(argv, argc, 0, argv[0]);
	}
	else
	{
		if (ft_strcmp(argv[1], "-C") == 0)
			ft_loop_files(argv, argc, 1, argv[0]);
		else
			ft_loop_files(argv, argc, 0, argv[0]);
	}
	return (0);
}
