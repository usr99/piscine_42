/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 05:32:04 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/17 17:27:42 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_FILE_H
# define FT_READ_FILE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_read_file(int fd);

#endif
