/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivannere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 16:55:33 by ivannere          #+#    #+#             */
/*   Updated: 2013/12/15 17:47:25 by ivannere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libget_next_line.h"

static int	ft_gnl_deleg(char **save, char **buffer, char **line);

int			ft_get_next_line(const int fd, char **line)
{
	int			rd;
	char		*buffer;
	static char	*save;

	if (fd <= -1 || line == NULL)
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	*line = (char *)malloc(sizeof(char));
	**line = '\0';
	while ((rd = read(fd, buffer, BUFF_SIZE)) > 0 || save != NULL)
	{
		*(buffer + rd) = '\0';
		if (ft_gnl_deleg(&save, &buffer, line))
			return (1);
	}
	free(buffer);
	if (rd == -1)
		return (-1);
	else if (rd == 0 && **line == '\0' && (save == NULL || *save == '\0'))
		return (0);
	return (rd);
}

static int	ft_gnl_deleg(char **save, char **buffer, char **line)
{
	size_t		size;
	char		*next;

	if (*save != NULL)
		*save = ft_strfjoin(save, buffer, 1);
	else
		*save = ft_strdup(*buffer);
	if ((int)ft_strcchr(*save, '\n') != -1)
	{
		size = ft_strcchr(*save, '\n');
		if (size < ft_strlen(*save))
		{
			next = ft_strsub(*save, 0, size);
			*line = ft_strfjoin(line, &next, 3);
			*save = ft_strfsub(save, size + 1, ft_strlen(*save) - size, 1);
		}
		else
			*line = ft_strfjoin(line, save, 3);
		free(*buffer);
		return (1);
	}
	else
		*line = ft_strfjoin(line, save, 3);
	return (0);
}
