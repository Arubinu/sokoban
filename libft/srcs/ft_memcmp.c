/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:45:03 by apergens          #+#    #+#             */
/*   Updated: 2014/01/06 00:47:40 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	*s1b;
	char	*s2b;

	i = -1;
	s1b = (char *)s1;
	s2b = (char *)s2;
	if (s1b == NULL || s2b == NULL)
		return (0);
	while (++i < (int)n && *(s1b + i) == *(s2b + i))
		;
	return (*(s1b + i) - *(s2b + i));
}
