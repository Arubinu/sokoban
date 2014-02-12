/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/17 02:05:01 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:48 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s2);
	if (!*s2)
		return ((char *)(s1 + ft_strlen(s1 - 1)));
	while (*(s1 + ++i) && (i + len - 1) < (int)n)
	{
		if (!ft_memcmp((s1 + i), s2, len - 1))
			return ((char *)(s1 + i));
	}
	return (NULL);
}
