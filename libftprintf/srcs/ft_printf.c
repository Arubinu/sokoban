/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:05:57 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*ptr;
	char		*str;
	size_t		len;

	len = 0;
	ptr = (char *)format;
	va_start(ap, format);
	while (*ptr && (len += ft_get_v_arg(ap, &ptr, &str, 1)))
		;
	va_end(ap);
	return ((int)len);
}
