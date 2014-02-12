/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:30:21 by apergens          #+#    #+#             */
/*   Updated: 2013/11/20 00:00:53 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(s1);
	while (*(s2 + ++i) && i < (int)n)
		*(s1 + len + i) = *(s2 + i);
	*(s1 + len + i) = '\0';
	return (s1);
}
