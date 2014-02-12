/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 08:55:48 by apergens          #+#    #+#             */
/*   Updated: 2014/01/20 08:56:55 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

int		ft_sdkn_check(void)
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		nbr;
	char	****file;

	ft_sdkn_filelevel(0, 0, &file);
	if ((y = -1) == -1 && (!*file || !**file))
		return (0);
	w = ft_sdkn_mapsize(0, 0, 0);
	h = ft_sdkn_mapsize(0, 0, 1);
	while (++y < h && (x = -1) && *(*file + y) && *(*(*file + y) + (x + 1)))
	{
		while (++x < w && *(*(*file + y) + x))
		{
			if ((nbr = ft_atoi(*(*(*file + y) + x))) == 3)
				return (0);
		}
	}
	return (1);
}
