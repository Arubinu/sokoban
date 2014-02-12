/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:58:29 by apergens          #+#    #+#             */
/*   Updated: 2013/11/26 11:24:55 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char)* (ft_strlen(s2) + 1));
	ft_memcpy(temp, s2, n);
	ft_memcpy(s1, temp, n);
	return (s1);
}
