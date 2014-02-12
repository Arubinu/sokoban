/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:58:29 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:06:47 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int		i;
	char	*s1b;
	char	*s2b;

	i = -1;
	s1b = (char *)s1;
	s2b = (char *)s2;
	while (++i < (int)n)
	{
		*(s1b + i) = *(s2b + i);
		if (*(s2b + i) == c)
			return (s1b + i + 1);
	}
	return (NULL);
}
