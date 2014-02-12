/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libget_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:31:17 by apergens          #+#    #+#             */
/*   Updated: 2013/12/08 03:57:17 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# include "libft.h"

# define BUFF_SIZE 42

int		ft_get_nbr_lines(const char *file);
int		ft_get_next_line(const int fd, char **line);

#endif
