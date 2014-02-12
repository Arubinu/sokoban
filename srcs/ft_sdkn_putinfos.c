/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdkn_putinfos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 11:30:32 by apergens          #+#    #+#             */
/*   Updated: 2014/01/23 02:23:50 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sokoban.h"

int		ft_sdkn_putinfos(t_game *game, int hits, int reset, int val)
{
	char		*str;
	char		*tmp;
	static int	h;
	static int	r;

	if (val == 1)
		h = hits;
	else if (val == 2)
		r = reset;
	else if (val == 3)
		return (h);
	else if (val == 4)
		return (r);
	else if (val == -1)
	{
		h += hits;
		r += reset;
	}
	else if (val == -2)
		h += hits;
	else if (val == -3)
		r += reset;
	if (val != 0)
		return (0);
	tmp = ft_itoa(h);
	str = ft_strfjoin2("Nombre de coups (", &tmp, 1);
	str = ft_strfjoin1(&str, ") - Nombre d'essais (", 1);
	tmp = ft_itoa(r);
	str = ft_strfjoin(&str, &tmp, 3);
	str = ft_strfjoin1(&str, ")", 1);
	ft_sdkn_putcmt(game->image.surf, str, -1, WIN_H - 25);
	free(str);
	return (0);
}
