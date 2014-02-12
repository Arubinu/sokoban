/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:58:29 by apergens          #+#    #+#             */
/*   Updated: 2013/11/22 12:41:53 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*s1b;
	const char	*s2b;

	i = 0;
	s1b = (char *)s1;
	s2b = (const char *)s2;
	while (++i <= n)
		*(s1b + (i - 1)) = *(s2b + (i - 1));
	return (s1b);
}
