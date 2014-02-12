/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_v_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2013/12/25 21:13:05 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_get_v_arg(va_list ap, char **format, char **out, int fd)
{
	int		i;
	int		ret;

	i = ft_strcchr(*format, '%');
	if (i == -1)
	{
		if ((i = ft_strlen(*format)))
			write(fd, *format, i);
		*format += i;
		return (i);
	}
	write(fd, *format, i);
	ret = ft_printf_arg(ap, (*format + i), out);
	*format += i + 2;
	write(fd, *out, ft_strlen(*out));
	return (i + ret);
}
