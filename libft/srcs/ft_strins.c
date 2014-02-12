/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2013/12/18 13:13:21 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strins(char *s1, char *s2, size_t start, size_t len)
{
	char	*ret;
	char	*tmp;

	ret = ft_strsub(s1, 0, start);
	tmp = ft_strsub(s1, start + len, ft_strlen(s1 - (start + len)));
	ret = ft_strfjoin(&ret, &s2, 1);
	ret = ft_strfjoin(&ret, &tmp, 3);
	return (ret);
}
