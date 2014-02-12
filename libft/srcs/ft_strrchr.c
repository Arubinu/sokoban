/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:30:43 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:50 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen((char *)s) + 1;
	while (--i >= 0)
	{
		if (*(s + i) == c)
			return ((char *)s + i);
	}
	if (*(s + i) == c)
		return ((char *)s + i);
	return (NULL);
}
