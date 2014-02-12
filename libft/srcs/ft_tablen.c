/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:31:17 by apergens          #+#    #+#             */
/*   Updated: 2014/01/19 23:40:09 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(char ****tab, int line)
{
	int		i;

	i = 0;
	if (tab == NULL || *tab == NULL || **tab == NULL)
		return (i);
	while ((*(*tab + line) + i) != NULL && *(*(*tab + line) + (i++)) != NULL)
		;
	return (i - 1);
}
