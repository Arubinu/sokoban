/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by apergens          #+#    #+#             */
/*   Updated: 2014/01/03 02:07:58 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_xtoa(int n, int on)
{
	int		i;
	int		j;
	int		multi;
	char	*ret;
	char	*val;

	i = -1;
	ret = ft_strnew(2);
	val = ft_strdup("0123456789abcdef");
	multi = (int)ft_strlen(val);
	while (++i < 2 && (j = 0) == 0)
	{
		while (++j <= (int)ft_strlen(val))
		{
			if (n < j * multi)
			{
				multi = 1;
				n -= (j - 1) * (int)ft_strlen(val) * multi;
				*(ret + i) = *(val + j - 1);
				*(ret + i) -= (on && ft_isalpha(*(ret + i))) ? 'a' - 'A' : 0;
				break ;
			}
		}
	}
	return (ret);
}
