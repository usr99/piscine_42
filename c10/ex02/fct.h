/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:22:10 by mamartin          #+#    #+#             */
/*   Updated: 2020/08/25 19:22:12 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
# define FCT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str, int fd);
void	ft_save_file_content(char *content, char new_carac, int length);
void	ft_clear_file_content(char *content, int size);

#endif
