/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:06:29 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		state;
	char	*result;

	state = (n < 0) ? 1 : 0;
	i = ft_ilen(n);
	result = ft_memalloc(i + 1);
	if (state)
	{
		i--;
		*result = '-';
		*(result + i) = ((n % 10) * -1) + '0';
		n = (n / 10) * -1;
	}
	while (--i >= state - 1 && n >= 10)
	{
		*(result + i) = (n % 10) + '0';
		n /= 10;
	}
	if (n || !state)
		*(result + i) = (n % 10) + '0';
	return (result);
}
