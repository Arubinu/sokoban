/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_mapsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 00:59:54 by apergens          #+#    #+#             */
/*   Updated: 2014/01/20 01:00:00 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

int		ft_sdkn_mapsize(int w, int h, int set)
{
	static int	save_w;
	static int	save_h;

	if (set == -1)
	{
		save_w = w;
		save_h = h;
	}
	if (set == 1)
		return (save_h);
	return (save_w);
}
